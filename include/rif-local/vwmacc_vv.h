// vwmacc.vv vd, vs2, vs1
VI_CHECK_DSS(true);
VI_VV_MUL_ADD_LOOP_WIDEN
({
  VI_WIDE_OP_AND_ASSIGN(vs2, vs1, vd_w, *, +, int);
})