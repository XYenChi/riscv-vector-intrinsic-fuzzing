// COMMAND: random_gen -r MsltVX8VBool -n 1 -l 7 --has-ta --has-ma -c MsltVX8VBool.c --has-policy
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
int8_t value_0[7];
int8_t value_1;
int8_t value_2[7];
void vinit_rif_operator_1() {
int8_t tmp[] = {-56,79,55,-14,26,-73,-57,};
for (int i=0; i<7;++i) {value_0[i] = tmp[i];
}
}
void vinit_rif_operator_2() {
int8_t tmp = -22;
value_1 = tmp;
}
void vmslt_vx_operator_0() {
int8_t *placeholder0 = value_0;
int8_t placeholder1 = value_1;
int8_t *placeholder2 = value_2;

int placeholder3 = 7;

for (size_t vl; placeholder3 > 0; placeholder3 -= vl) {
vl = vsetvl_e8m1(placeholder3);
vint8m1_t vec_value_0_0= vle8_v_i8m1(placeholder0, vl);

vbool8_t vec_value_2_0= vmslt_vx_i8m1_b8(vec_value_0_0, placeholder1, vl);

{
size_t vlmax = vsetvlmax_e8m1();
vint8m1_t zero = vmv_v_x_i8m1(0, vlmax);
vint8m1_t vec_store = vmerge_vxm_i8m1(vec_value_2_0, zero, 1, vl);
vse8_v_i8m1(placeholder2, vec_store, vl);
}

placeholder0 += vl;
placeholder2 += vl;
}
}
int golden_vinit_rif_operator_1() {
return 1;
}
int golden_vinit_rif_operator_2() {
return 1;
}
int golden_vmslt_vx_operator_0() {
int8_t tmp[] = {1,0,0,0,0,1,1,};
for (int i=0; i<7;++i)
if(value_2[i] != tmp[i]) {
return 0;
}
return 1;
}
int main () {
vinit_rif_operator_1();
vinit_rif_operator_2();
vmslt_vx_operator_0();
printf("operator_1 : %s\n", golden_vinit_rif_operator_1() ? "pass" : "fail");
printf("operator_2 : %s\n", golden_vinit_rif_operator_2() ? "pass" : "fail");
printf("operator_0 : %s\n", golden_vmslt_vx_operator_0() ? "pass" : "fail");
int ret = 1; // 1 = success
ret &= golden_vinit_rif_operator_1();
ret &= golden_vinit_rif_operator_2();
ret &= golden_vmslt_vx_operator_0();
if (!ret) return 1;
return 0; }
