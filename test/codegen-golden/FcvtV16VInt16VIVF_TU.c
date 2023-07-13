// COMMAND: random_gen -r FcvtV16VInt16VIVF_TU -n 1 -l 7 --has-ta --has-ma -c FcvtV16VInt16VIVF_TU.c --has-policy
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
int16_t value_0[7];
float16_t value_1[7];
int16_t value_2[7];
void vinit_rif_operator_1() {
int16_t tmp[] = {-5546,7893,5458,-1417,2596,-7226,-5630,};
for (int i=0; i<7;++i) {value_0[i] = tmp[i];
}
}
void vinit_rif_operator_2() {
uint16_t tmp[] = {28575,29523,28707,29046,29100,27386,28475,};
for (int i=0; i<7;++i) {union { uint16_t u16; float16_t f; } converter;
converter.u16 = tmp[i];
value_1[i] = converter.f;
}
}
void vfcvt_x_f_v_operator_0() {
int16_t *placeholder0 = value_0;
float16_t *placeholder1 = value_1;
int16_t *placeholder2 = value_2;

int placeholder3 = 7;

for (size_t vl; placeholder3 > 0; placeholder3 -= vl) {
vl = 2;
size_t tail_vl = 1;
vint16m1_t vec_value_0_0= vle16_v_i16m1(placeholder0, vl);
vfloat16m1_t vec_value_1_0= vle16_v_f16m1(placeholder1, vl);

vint16m1_t vec_value_2_0= vfcvt_x_f_v_i16m1_tu(vec_value_0_0, vec_value_1_0, tail_vl);

vse16_v_i16m1(placeholder2, vec_value_2_0, vl);

placeholder0 += vl;
placeholder1 += vl;
placeholder2 += vl;
}
}
int golden_vinit_rif_operator_1() {
return 1;
}
int golden_vinit_rif_operator_2() {
return 1;
}
int golden_vfcvt_x_f_v_operator_0() {
int16_t tmp[] = {7804,7893,8472,-1417,11616,-7226,7404,};
for (int i=0; i<7;++i)
if(value_2[i] != tmp[i]) {
return 0;
}
return 1;
}
int main () {
vinit_rif_operator_1();
vinit_rif_operator_2();
vfcvt_x_f_v_operator_0();
printf("operator_1 : %s\n", golden_vinit_rif_operator_1() ? "pass" : "fail");
printf("operator_2 : %s\n", golden_vinit_rif_operator_2() ? "pass" : "fail");
printf("operator_0 : %s\n", golden_vfcvt_x_f_v_operator_0() ? "pass" : "fail");
int ret = 1; // 1 = success
ret &= golden_vinit_rif_operator_1();
ret &= golden_vinit_rif_operator_2();
ret &= golden_vfcvt_x_f_v_operator_0();
if (!ret) return 1;
return 0; }
