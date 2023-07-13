// vadc.vxm vd, vs2, rs1, carry
VI_VX_LOOP_WITH_CARRY
({
  const uint128_t op_mask = (UINT64_MAX >> (64 - sew));
  uint128_t res = (op_mask & rs1) + (op_mask & vs2) + carry;
  vd = res;
})
