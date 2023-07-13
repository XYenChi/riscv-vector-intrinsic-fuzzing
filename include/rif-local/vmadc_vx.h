// vmadc.vx vd, vs2, rs1
VI_VX_LOOP
({
  const uint64_t mmask = 1;
  const uint128_t op_mask = (UINT64_MAX >> (64 - sew));
  uint128_t res = (op_mask & rs1) + (op_mask & vs2);
  vd = (res >> sew) & mmask;
})
