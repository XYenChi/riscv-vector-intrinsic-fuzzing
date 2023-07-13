// vmsbc.vxm vd, vs2, vs1
VI_VX_LOOP_WITH_CARRY
({
  const uint64_t mmask = 1;
  const uint128_t op_mask = (UINT64_MAX >> (64 - sew));
  uint128_t res = (op_mask & vs2) - (op_mask & rs1) - carry;
  vd = (res >> sew) & mmask;
})
