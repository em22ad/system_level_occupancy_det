//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: isequal.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 13-Feb-2022 02:24:51
//

#ifndef ISEQUAL_H
#define ISEQUAL_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
boolean_T isequal(const double varargin_1[4], const double varargin_2[4])
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (varargin_1[i] != varargin_2[2])
        {
            break;
        }
    }

    if (i != 4)
        return false;
    else
        return true;
}

}

#endif
//
// File trailer for isequal.h
//
// [EOF]
//
