//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: isequal.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 13-Feb-2022 02:24:51
//

// Include Files
#include "isequal.h"

// Function Definitions
//
// Arguments    : const double varargin_1[4]
//                const double varargin_2[4]
// Return Type  : boolean_T
//
namespace coder {
boolean_T isequal(const double varargin_1[4], const double varargin_2[4])
{
  int k;
  boolean_T exitg1;
  boolean_T p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    if (!(varargin_1[k] == varargin_2[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  return p;
}

} // namespace coder

//
// File trailer for isequal.cpp
//
// [EOF]
//
