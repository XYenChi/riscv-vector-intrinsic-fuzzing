// COMMAND: random_gen -r Vluxei64V8VInt8SIVU_TA -n 1 -l 7 --has-ta --has-ma -c Vluxei64V8VInt8SIVU_TA.c --has-policy
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
uint64_t value_1[7];
int8_t value_2[7];
void vinit_rif_operator_1() {
int8_t tmp[] = {-56,79,55,-14,26,-73,-57,};
for (int i=0; i<7;++i) {value_0[i] = tmp[i];
}
}
void vinit_rif_operator_2() {
uint64_t tmp[] = {3902764ull,7500210ull,4235251ull,5592077ull,5806864ull,1786754ull,3702157ull,};
for (int i=0; i<7;++i) {value_1[i] = tmp[i];
}
}
void vluxei64_v_operator_0() {
int8_t *placeholder0 = value_0;
uint64_t *placeholder1 = value_1;
int8_t *placeholder2 = value_2;
int placeholder3 = 7;

size_t placeholder4 = 0;
for (size_t vl; placeholder3 > 0; placeholder3 -= vl) {
vl = 2;
size_t tail_vl = 1;
vuint64m8_t vec_value_1_0= vle64_v_u64m8(placeholder1, vl);
{
vec_value_1_0 = vremu_vx_u64m8(vec_value_1_0, 7, vl);
}
vec_value_1_0 = vmul_vx_u64m8(vec_value_1_0, 1, vl);
vint8m1_t vec_value_2_0= vluxei64_v_i8m1_ta(placeholder0, vec_value_1_0, tail_vl);
vse8_v_i8m1(placeholder2, vec_value_2_0, vl);
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
int golden_vluxei64_v_operator_0() {
int8_t tmp[] = {-73,-1,-57,-1,-56,-1,26,};
for (int i=0; i<7;++i)
if(value_2[i] != tmp[i]) {
return 0;
}
return 1;
}
int main () {
vinit_rif_operator_1();
vinit_rif_operator_2();
vluxei64_v_operator_0();
printf("operator_1 : %s\n", golden_vinit_rif_operator_1() ? "pass" : "fail");
printf("operator_2 : %s\n", golden_vinit_rif_operator_2() ? "pass" : "fail");
printf("operator_0 : %s\n", golden_vluxei64_v_operator_0() ? "pass" : "fail");
int ret = 1; // 1 = success
ret &= golden_vinit_rif_operator_1();
ret &= golden_vinit_rif_operator_2();
ret &= golden_vluxei64_v_operator_0();
if (!ret) return 1;
return 0; }
