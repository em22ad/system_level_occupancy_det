//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bayes_filter_types.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 05:49:45
//

#ifndef BAYES_FILTER_TYPES_H
#define BAYES_FILTER_TYPES_H

// Include Files
#include "rtwtypes.h"

#include <ostream>

using namespace std;

// Type Definitions
struct emxArray_char_T_1x11
{
    char data[11];
    int size[2];
};

struct cell_wrap_0
{
    emxArray_char_T_1x11 f1;

    //friend emxArray_char_T_1x11;
    friend ostream & operator<< (ostream &os, cell_wrap_0 &val)
    {
        os << "data is " << val.f1.data << endl;
        os << "Size are " << val.f1.size[0] << " " << val.f1.size[1] << endl;

        return os;
    }
};

#endif
//
// File trailer for bayes_filter_types.h
//
// [EOF]
//
