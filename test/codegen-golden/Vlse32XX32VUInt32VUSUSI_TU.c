// COMMAND: random_gen -r Vlse32XX32VUInt32VUSUSI_TU -n 1 -l 7 --has-ta --has-ma -c Vlse32XX32VUInt32VUSUSI_TU.c --has-policy
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
ptrdiff_t value_2;
uint32_t value_3[7];
void vinit_rif_operator_1() {
uint32_t tmp[] = {2227093u,8946104u,7728937u,4291503u,6298054u,1387269u,2185159u,};
for (int i=0; i<7;++i) {value_0[i] = tmp[i];
}
}
void vinit_rif_operator_3() {
ptrdiff_t tmp = 3902764ll;
value_2 = tmp;
}
void vinit_rif_operator_2() {
uint32_t tmp[] = {7500210u,4235251u,5592077u,5806864u,1786754u,3702157u,6442165u,};
for (int i=0; i<7;++i) {value_1[i] = tmp[i];
}
}
void vlse32_v_operator_0() {
uint32_t *placeholder0 = value_0;
uint32_t *placeholder1 = value_1;
ptrdiff_t placeholder2 = value_2;
uint32_t *placeholder3 = value_3;
uint32_t *placeholder4 = value_3;
int placeholder5 = 7;

for (size_t vl; placeholder5 > 0; placeholder5 -= vl) {
vl = vsetvl_e32m1(placeholder5);
vuint32m1_t placeholder6= vmv_v_x_u32m1(0, vsetvlmax_e32m1());
vse32_v_u32m1(placeholder4, placeholder6, vl);
placeholder4 += vl;
}
placeholder2 = (placeholder2 % 4) + 1;
int placeholder7 = 7;

size_t placeholder8 = 0;
for (size_t vl; placeholder7 > 0; placeholder7 -= vl) {
vl = 2;
size_t tail_vl = 1;
vuint32m1_t vec_value_0_0= vle32_v_u32m1(placeholder0, vl);
if (placeholder8 < 7) {
vuint32m1_t placeholder9= vmv_v_x_u32m1(0, vsetvlmax_e32m1());
vse32_v_u32m1(placeholder3, placeholder9, vl);
size_t placeholder10 = vl;
vl = vl < (7 - placeholder8 + placeholder2 - 1) / placeholder2 ? 
vl : (7 - placeholder8 + placeholder2 - 1) / placeholder2;
int32_t placeholder11 = placeholder2;
placeholder2 *= 4;
vuint32m1_t vec_value_3_0= vlse32_v_u32m1_tu(vec_value_0_0, placeholder1, placeholder2, tail_vl);
vse32_v_u32m1(placeholder3, vec_value_3_0, vl);
vl = placeholder10; // recover vl
placeholder2 = placeholder11; // recover stride
}
else {
vuint32m1_t placeholder12= vmv_v_x_u32m1(0, vsetvlmax_e32m1());
vse32_v_u32m1(placeholder3, placeholder12, vl);
};
placeholder0 += vl;
placeholder1 += vl * placeholder2;
placeholder3 += vl;
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
int golden_vlse32_v_operator_0() {
uint32_t tmp[] = {7500210u,8946104u,5592077u,4291503u,1786754u,1387269u,6442165u,};
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
vlse32_v_operator_0();
printf("operator_1 : %s\n", golden_vinit_rif_operator_1() ? "pass" : "fail");
printf("operator_3 : %s\n", golden_vinit_rif_operator_3() ? "pass" : "fail");
printf("operator_2 : %s\n", golden_vinit_rif_operator_2() ? "pass" : "fail");
printf("operator_0 : %s\n", golden_vlse32_v_operator_0() ? "pass" : "fail");
int ret = 1; // 1 = success
ret &= golden_vinit_rif_operator_1();
ret &= golden_vinit_rif_operator_3();
ret &= golden_vinit_rif_operator_2();
ret &= golden_vlse32_v_operator_0();
if (!ret) return 1;
return 0; }
