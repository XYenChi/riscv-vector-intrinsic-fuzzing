// COMMAND: random_gen -r Vsoxei32V32VoidVUVU -n 1 -l 7 --has-ta --has-ma -c Vsoxei32V32VoidVUVU.c --has-policy
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
uint32_t value_0[7];
uint32_t value_1[7];
uint32_t value_2[7];
void vinit_rif_operator_1() {
uint32_t tmp[] = {2227093u,8946104u,7728937u,4291503u,6298054u,1387269u,2185159u,};
for (int i=0; i<7;++i) {value_0[i] = tmp[i];
}
}
void vinit_rif_operator_2() {
uint32_t tmp[] = {3902764u,7500210u,4235251u,5592077u,5806864u,1786754u,3702157u,};
for (int i=0; i<7;++i) {value_1[i] = tmp[i];
}
}
void vsoxei32_v_operator_0() {
uint32_t *placeholder0 = value_0;
uint32_t *placeholder1 = value_1;
uint32_t *placeholder2 = value_2;
uint32_t *placeholder3 = value_2;
int placeholder4 = 7;

for (size_t vl; placeholder4 > 0; placeholder4 -= vl) {
vl = vsetvl_e32m1(placeholder4);
vuint32m1_t placeholder5= vmv_v_x_u32m1(0, vsetvlmax_e32m1());
vse32_v_u32m1(placeholder3, placeholder5, vl);
placeholder3 += vl;
}
int placeholder6 = 7;

size_t placeholder7 = 0;
for (size_t vl; placeholder6 > 0; placeholder6 -= vl) {
vl = vsetvl_e32m1(placeholder6);
vuint32m1_t vec_value_1_0= vle32_v_u32m1(placeholder1, vl);
vuint32m1_t vec_value_0_0= vle32_v_u32m1(placeholder0, vl);
if (7 < 4294967295) {
vec_value_1_0 = vremu_vx_u32m1(vec_value_1_0, 7, vl);
}
vec_value_1_0 = vmul_vx_u32m1(vec_value_1_0, 4, vl);
vsoxei32_v_u32m1(placeholder2, vec_value_1_0, vec_value_0_0, vl);
placeholder0 += vl;
placeholder1 += vl;
}
}
int golden_vinit_rif_operator_1() {
return 1;
}
int golden_vinit_rif_operator_2() {
return 1;
}
int golden_vsoxei32_v_operator_0() {
uint32_t tmp[] = {6298054u,4291503u,0u,0u,2185159u,2227093u,7728937u,};
for (int i=0; i<7;++i)
if(value_2[i] != tmp[i]) {
return 0;
}
return 1;
}
int main () {
vinit_rif_operator_1();
vinit_rif_operator_2();
vsoxei32_v_operator_0();
printf("operator_1 : %s\n", golden_vinit_rif_operator_1() ? "pass" : "fail");
printf("operator_2 : %s\n", golden_vinit_rif_operator_2() ? "pass" : "fail");
printf("operator_0 : %s\n", golden_vsoxei32_v_operator_0() ? "pass" : "fail");
int ret = 1; // 1 = success
ret &= golden_vinit_rif_operator_1();
ret &= golden_vinit_rif_operator_2();
ret &= golden_vsoxei32_v_operator_0();
if (!ret) return 1;
return 0; }
