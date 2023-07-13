// COMMAND: random_gen -r Vsse8XX8VoidVBSIVI_m -n 1 -l 7 --has-ta --has-ma -c Vsse8XX8VoidVBSIVI_m.c --has-policy
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
int8_t value_1[7];
ptrdiff_t value_2;
int8_t value_3[7];
void vinit_rif_operator_1() {
int8_t tmp[] = {0,1,1,0,1,0,0,};
for (int i=0; i<7;++i) {value_0[i] = tmp[i];
}
}
void vinit_rif_operator_3() {
ptrdiff_t tmp = 3902764ll;
value_2 = tmp;
}
void vinit_rif_operator_2() {
int8_t tmp[] = {50,-15,12,16,-65,-26,29,};
for (int i=0; i<7;++i) {value_1[i] = tmp[i];
}
}
void vsse8_v_operator_0() {
int8_t *placeholder0 = value_0;
int8_t *placeholder1 = value_1;
ptrdiff_t placeholder2 = value_2;
int8_t *placeholder3 = value_3;
int8_t *placeholder4 = value_3;
int placeholder5 = 7;

for (size_t vl; placeholder5 > 0; placeholder5 -= vl) {
vl = vsetvl_e8m1(placeholder5);
vint8m1_t placeholder6= vmv_v_x_i8m1(0, vsetvlmax_e8m1());
vse8_v_i8m1(placeholder4, placeholder6, vl);
placeholder4 += vl;
}
placeholder2 = (placeholder2 % 4) + 1;
int placeholder7 = 7;

size_t placeholder8 = 0;
for (size_t vl; placeholder7 > 0; placeholder7 -= vl) {
vl = vsetvl_e8m1(placeholder7);
vint8m1_t vec_value_0= vle8_v_i8m1(placeholder0, vl);
vbool8_t mask_value_0_0= vmseq_vx_i8m1_b8(vec_value_0, 1, vl);
vint8m1_t vec_value_1_0= vle8_v_i8m1(placeholder1, vl);
if (placeholder8 < 7) {
vl = vl < (7 - placeholder8 + placeholder2 - 1) / placeholder2 ? 
vl : (7 - placeholder8 + placeholder2 - 1) / placeholder2;
int32_t placeholder9 = placeholder2;
placeholder2 *= 1;
vsse8_v_i8m1_m (mask_value_0_0, placeholder3, placeholder2, vec_value_1_0, vl);
placeholder2 = placeholder9; // recover stride
}
else {}
placeholder0 += vl;
placeholder1 += vl;
placeholder3 += vl * placeholder2;
placeholder8 += vl * placeholder2;
}
}
int golden_vinit_rif_operator_1() {
return 1;
}
int golden_vinit_rif_operator_3() {
return 1;
}
int golden_vinit_rif_operator_2() {
return 1;
}
int golden_vsse8_v_operator_0() {
int8_t tmp[] = {0,-15,12,0,-65,0,0,};
for (int i=0; i<7;++i)
if(value_3[i] != tmp[i]) {
return 0;
}
return 1;
}
int main () {
vinit_rif_operator_1();
vinit_rif_operator_3();
vinit_rif_operator_2();
vsse8_v_operator_0();
printf("operator_1 : %s\n", golden_vinit_rif_operator_1() ? "pass" : "fail");
printf("operator_3 : %s\n", golden_vinit_rif_operator_3() ? "pass" : "fail");
printf("operator_2 : %s\n", golden_vinit_rif_operator_2() ? "pass" : "fail");
printf("operator_0 : %s\n", golden_vsse8_v_operator_0() ? "pass" : "fail");
int ret = 1; // 1 = success
ret &= golden_vinit_rif_operator_1();
ret &= golden_vinit_rif_operator_3();
ret &= golden_vinit_rif_operator_2();
ret &= golden_vsse8_v_operator_0();
if (!ret) return 1;
return 0; }
