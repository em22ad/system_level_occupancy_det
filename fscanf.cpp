//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fscanf.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 08-Feb-2022 06:06:06
//

// Include Files
#include "fscanf.h"
#include "fileManager.h"
#include "coder_array.h"
#include "stdio.h"
#include <stdio.h>

// Function Definitions
//
// Arguments    : double fileID
//                ::coder::array<double, 1U> &A
// Return Type  : void
//
namespace coder {
void b_fscanf(double fileID, ::coder::array<double, 1U> &A)
{
  FILE *filestar;
  double tmpOut_f1;
  int numRead;
  boolean_T exitg1;
  boolean_T incompleteRead;
  tmpOut_f1 = 0.0;
  // If formatSpec contains a combination of numeric and character specifiers,
  // then fscanf converts each character to its numeric equivalent. This
  // conversion occurs even when the format explicitly skips all numeric values
  // (for example, formatSpec is '%*d %s').
  A.set_size(0);
  numRead = 1;
  getfilestar(fileID, &filestar, &incompleteRead);
  exitg1 = false;
  while ((!exitg1) && (numRead > 0)) {
    int tmpOut_f2;
    tmpOut_f2 = -1;
    numRead = fscanf(filestar, "%lf%n", &tmpOut_f1, &tmpOut_f2);
    if (tmpOut_f2 != -1) {
      numRead++;
    }
    incompleteRead = (numRead == 0);
    if (numRead > 0) {
      tmpOut_f2 = A.size(0);
      A.set_size(A.size(0) + 1);
      A[tmpOut_f2] = tmpOut_f1;
      incompleteRead = ((2 > numRead) || incompleteRead);
    }
    if (incompleteRead) {
      exitg1 = true;
    }
  }
}

} // namespace coder

//
// File trailer for fscanf.cpp
//
// [EOF]
//
