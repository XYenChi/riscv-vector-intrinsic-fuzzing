// COMMAND: random_gen -r FwredusumVS16SFloat32VF_TA -n 1 -l 7 --has-ta --has-ma -c FwredusumVS16SFloat32VF_TA.c --has-policy
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <riscv_vector.h>
typedef _Float16 float16_t;
typedef float float32_t;
typedef double float64_t;
#define isNaNF16UI( a ) (((~(a) & 0x7C00) == 0) && ((a) & 0x03FF))
#define isNaNF32UI( a ) (((~(a) & 0x7F800000) == 0) && ((a) & 0x007FFFFF))
#define isNaNF64UI( a ) (((~(a) & UINT64_C( 0x7FF0000000000000 )) == 0) && ((a) & UINT64_C( 0x000FFFFFFFFFFFFF )))
float16_t value_0[7];
float32_t value_1[7];
void vinit_rif_operator_1() {
uint16_t tmp[] = {27738,29790,29580,28721,29222,26987,27716,};
for (int i=0; i<7;++i) {union { uint16_t u16; float16_t f; } converter;
converter.u16 = tmp[i];
value_0[i] = converter.f;
}
}
void vfwredusum_vs_operator_0() {
float16_t *placeholder0 = value_0;
float32_t *placeholder1 = value_1;
int placeholder2 = 7;

vfloat32m1_t placeholder3= vfmv_v_f_f32m1(0, vsetvlmax_e32m1());
vfloat32m1_t placeholder4= vmv_v_v_f32m1(placeholder3, vsetvlmax_e32m1());
// This function initializes the output elements according to
// its
// tail policy and
// the reason doing so is to maintain VLA style.
// For ta policy, it initializes the value to all 1's, for tu it
// initializes to values of merge instead. E.g.
// in[5]:  [1, 1, 2, 2, 3]
// out[5]: [0, 0, 0, 0, 0] (global value is initialized to 0)
// vl:     4
// If we apply redsum_ta(out, in, vl), We want the result to be:
// [9, -1, -1, -1, -1].
// However, the vl is only 4, so it might result in something
// like:
// [6, -1, -1, -1, 3],
// but we want to maintain the output consistent as it's in VLA
// style,
// so one of the most convinent way to do so is to initialize
// the
// tail value in the beginning
// before performing actual computing, namely, getting into the
// loop.
memset(value_1, 0xff, sizeof(value_1));
for (size_t vl; placeholder2 > 0; placeholder2 -= vl) {
vl = vsetvl_e16m1(placeholder2);
vfloat16m1_t vec_value_0_0= vle16_v_f16m1(placeholder0, vl);
placeholder4 = vfwredusum_vs_f16m1_f32m1_ta(vec_value_0_0, placeholder4, vl);
placeholder0 += vl;
placeholder1 += vl;
}
float32_t *placeholder5 = value_1;
*placeholder5= vfmv_f_s_f32m1_f32(placeholder4);
}
int golden_vinit_rif_operator_1() {
return 1;
}
int golden_vfwredusum_vs_operator_0() {
uint64_t tmp[] = {1199645440u,4294967295u,4294967295u,4294967295u,4294967295u,4294967295u,4294967295u,};
union { float32_t f32; uint32_t u32; } converter;
union { float32_t f32; uint32_t u32; } converter2;
for (int i=0; i<7;++i){
converter.u32 = tmp[i];
converter2.f32 = value_1[i];
if(converter.f32 != converter2.f32 && !(isNaNF32UI(converter.u32) && isNaNF32UI(converter2.u32))) {
return 0;
}
}
return 1;
}
int main () {
vinit_rif_operator_1();
vfwredusum_vs_operator_0();
printf("operator_1 : %s\n", golden_vinit_rif_operator_1() ? "pass" : "fail");
printf("operator_0 : %s\n", golden_vfwredusum_vs_operator_0() ? "pass" : "fail");
int ret = 1; // 1 = success
ret &= golden_vinit_rif_operator_1();
ret &= golden_vfwredusum_vs_operator_0();
if (!ret) return 1;
return 0; }
