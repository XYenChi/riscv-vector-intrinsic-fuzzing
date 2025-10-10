#ifndef RIF_PROCESSOR_H
#define RIF_PROCESSOR_H
#include <cstdint>
typedef uint64_t reg_t;

enum VRM {
  RNU = 0, // round-to-nearest-up
  RNE,     // round-to-nearest-even
  RDN,     // round-to-nearest-down
  ROD,     // round-to-nearest-odd
  INVALID_RM
};

enum FloatRM {
  RNE_FRM = 0, // Round to Nearest, ties to Even
  RTZ_FRM,     // Round towards Zero
  RDN_FRM,     // Round Down
  RUP_FRM,     // Round Up
  RMM_FRM,     // Round to Nearest, ties to Max Magnitude
  INVALID_FRM
};

struct Processor {
  struct VectorUnit {
    unsigned vsew;      // sew
    VRM xrm = VRM::RNU; // rounding mode
    uint64_t vlmax, VLEN;  // maximum vector length
    VRM get_vround_mode() { return xrm; }
    void set_vround_mode(int mode) {
      if (mode >= RNU && mode < INVALID_RM)
        xrm = static_cast<VRM>(mode);
      else
        xrm = INVALID_RM;
    }
    FloatRM frm = FloatRM::RNE_FRM; // float point rounding mode
    FloatRM get_fround_mode() { return frm; }
    void set_fround_mode(int mode) {
      if (mode >= RNE_FRM && mode < INVALID_FRM)
        frm = static_cast<FloatRM>(mode);
      else
        frm = INVALID_FRM;
    }
    // vector element for various SEW
    template<class T> T& elt(void* vReg, uint64_t n, bool is_write = false) {
      T* vRegPtr = reinterpret_cast<T*>(vReg);
      return vRegPtr[n];
    }
  };
  VectorUnit VU;
};

extern Processor P;
extern Processor *p;

#endif