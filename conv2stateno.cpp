//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: conv2stateno.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 05:49:45
//

// Include Files
#include "pch.h"
#include "conv2stateno.h"
#include "bayes_filter_data.h"
#include "bayes_filter_types.h"

// Function Definitions
//
// Arguments    : const double obs[3]
//                double *state
//                cell_wrap_0 *g_label
// Return Type  : void
//
void conv2stateno(const double obs[3], double *state, cell_wrap_0 *g_label)
{
    static const char cv1[7] {'X', '_', '1', ',', 'X', '_', '2'};
    static const char cv2[7] {'X', '_', '1', ',', 'X', '_', '3'};
    static const char cv3[7] {'X', '_', '2', ',', 'X', '_', '3'};
    static const char b_cv[5] {'U', 'n', 'o', 'c', 'c'};
    static const signed char iv[3] {0, 1, 0};
    static const signed char iv1[3] {0, 0, 1};
    static const signed char iv2[3] {1, 0, 0};
    static const signed char iv3[3] {0, 1, 1};
    static const signed char iv4[3] {1, 0, 1};
    static const signed char iv5[3] {1, 1, 0};
    cell_wrap_0 r;
    int b_state;
    int k;
    boolean_T exitg1;
    boolean_T p;
    b_state = 1;
    g_label->f1.size[0] = 1;
    g_label->f1.size[1] = 5;
    for (k = 0; k < 5; k++)
    {
        g_label->f1.data[k] = b_cv[k];
    }
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3))
    {
        if (!(obs[k] == 0.0))
        {
            p = false;
            exitg1 = true;
        }
        else
        {
            k++;
        }
    }
    if (p)
    {
        //  UO
        r.f1.size[0] = 1;
        r.f1.size[1] = 5;
        for (k = 0; k < 5; k++)
        {
            r.f1.data[k] = b_cv[k];
        }
        *g_label = r;
    }
    else
    {
        p = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 3))
        {
            if (!(obs[k] == iv[k]))
            {
                p = false;
                exitg1 = true;
            }
            else
            {
                k++;
            }
        }
        if (p)
        {
            //  X1
            b_state = 2;
            r.f1.size[0] = 1;
            r.f1.size[1] = 3;
            r.f1.data[0] = 'X';
            r.f1.data[1] = '_';
            r.f1.data[2] = '1';
            *g_label = r;
        }
        else
        {
            p = true;
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < 3))
            {
                if (!(obs[k] == iv1[k]))
                {
                    p = false;
                    exitg1 = true;
                }
                else
                {
                    k++;
                }
            }
            if (p)
            {
                //  X2
                b_state = 3;
                r.f1.size[0] = 1;
                r.f1.size[1] = 3;
                r.f1.data[0] = 'X';
                r.f1.data[1] = '_';
                r.f1.data[2] = '2';
                *g_label = r;
            }
            else
            {
                p = true;
                k = 0;
                exitg1 = false;
                while ((!exitg1) && (k < 3))
                {
                    if (!(obs[k] == iv2[k]))
                    {
                        p = false;
                        exitg1 = true;
                    }
                    else
                    {
                        k++;
                    }
                }
                if (p)
                {
                    //  X3
                    b_state = 4;
                    r.f1.size[0] = 1;
                    r.f1.size[1] = 3;
                    r.f1.data[0] = 'X';
                    r.f1.data[1] = '_';
                    r.f1.data[2] = '3';
                    *g_label = r;
                }
                else
                {
                    p = true;
                    k = 0;
                    exitg1 = false;
                    while ((!exitg1) && (k < 3))
                    {
                        if (!(obs[k] == iv3[k]))
                        {
                            p = false;
                            exitg1 = true;
                        }
                        else
                        {
                            k++;
                        }
                    }
                    if (p)
                    {
                        //  X12
                        b_state = 5;
                        r.f1.size[0] = 1;
                        r.f1.size[1] = 7;
                        for (k = 0; k < 7; k++)
                        {
                            r.f1.data[k] = cv1[k];
                        }
                        *g_label = r;
                    }
                    else
                    {
                        p = true;
                        k = 0;
                        exitg1 = false;
                        while ((!exitg1) && (k < 3))
                        {
                            if (!(obs[k] == iv4[k]))
                            {
                                p = false;
                                exitg1 = true;
                            }
                            else
                            {
                                k++;
                            }
                        }
                        if (p)
                        {
                            //  X13
                            b_state = 6;
                            r.f1.size[0] = 1;
                            r.f1.size[1] = 7;
                            for (k = 0; k < 7; k++)
                            {
                                r.f1.data[k] = cv2[k];
                            }
                            *g_label = r;
                        }
                        else
                        {
                            p = true;
                            k = 0;
                            exitg1 = false;
                            while ((!exitg1) && (k < 3))
                            {
                                if (!(obs[k] == iv5[k]))
                                {
                                    p = false;
                                    exitg1 = true;
                                }
                                else
                                {
                                    k++;
                                }
                            }
                            if (p)
                            {
                                //  X23
                                b_state = 7;
                                r.f1.size[0] = 1;
                                r.f1.size[1] = 7;
                                for (k = 0; k < 7; k++)
                                {
                                    r.f1.data[k] = cv3[k];
                                }
                                *g_label = r;
                            }
                            else
                            {
                                p = true;
                                k = 0;
                                exitg1 = false;
                                while ((!exitg1) && (k < 3))
                                {
                                    if (!(obs[k] == 1.0))
                                    {
                                        p = false;
                                        exitg1 = true;
                                    }
                                    else
                                    {
                                        k++;
                                    }
                                }
                                if (p)
                                {
                                    //  X123
                                    b_state = 8;
                                    r.f1.size[0] = 1;
                                    r.f1.size[1] = 11;
                                    for (k = 0; k < 11; k++)
                                    {
                                        r.f1.data[k] = cv[k];
                                    }
                                    *g_label = r;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    *state = b_state;
}

//
// File trailer for conv2stateno.cpp
//
// [EOF]
//
