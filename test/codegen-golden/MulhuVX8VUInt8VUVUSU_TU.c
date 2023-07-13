// COMMAND: random_gen -r MulhuVX8VUInt8VUVUSU_TU -n 1 -l 7 --has-ta --has-ma -c MulhuVX8VUInt8VUVUSU_TU.c --has-policy
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
uint8_t value_0[7];
uint8_t value_1[7];
uint8_t value_2;
uint8_t value_3[7];
void vinit_rif_operator_1() {
uint8_t tmp[] = {22,90,78,43,63,14,22,};
for (int i=0; i<7;++i) {value_0[i] = tmp[i];
}
}
void vinit_rif_operator_3() {
uint8_t tmp = 39;
value_2 = tmp;
}
void vinit_rif_operator_2() {
uint8_t tmp[] = {75,42,56,58,18,37,65,};
for (int i=0; i<7;++i) {value_1[i] = tmp[i];
}
}
void vmulhu_vx_operator_0() {
uint8_t *placeholder0 = value_0;
uint8_t *placeholder1 = value_1;
uint8_t placeholder2 = value_2;
uint8_t *placeholder3 = value_3;

int placeholder4 = 7;

for (size_t vl; placeholder4 > 0; placeholder4 -= vl) {
vl = 2;
size_t tail_vl = 1;
vuint8m1_t vec_value_0_0= vle8_v_u8m1(placeholder0, vl);
vuint8m1_t vec_value_1_0= vle8_v_u8m1(placeholder1, vl);

vuint8m1_t vec_value_3_0= vmulhu_vx_u8m1_tu(vec_value_0_0, vec_value_1_0, placeholder2, tail_vl);

vse8_v_u8m1(placeholder3, vec_value_3_0, vl);

placeholder0 += vl;
placeholder1 += vl;
placeholder3 += vl;
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
int golden_vmulhu_vx_operator_0() {
uint8_t tmp[] = {11,90,8,43,2,14,9,};
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
vmulhu_vx_operator_0();
printf("operator_1 : %s\n", golden_vinit_rif_operator_1() ? "pass" : "fail");
printf("operator_3 : %s\n", golden_vinit_rif_operator_3() ? "pass" : "fail");
printf("operator_2 : %s\n", golden_vinit_rif_operator_2() ? "pass" : "fail");
printf("operator_0 : %s\n", golden_vmulhu_vx_operator_0() ? "pass" : "fail");
int ret = 1; // 1 = success
ret &= golden_vinit_rif_operator_1();
ret &= golden_vinit_rif_operator_3();
ret &= golden_vinit_rif_operator_2();
ret &= golden_vmulhu_vx_operator_0();
if (!ret) return 1;
return 0; }
