//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bayes_filter.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 05:49:45
//

// Include Files
#include "pch.h"
#include "bayes_filter.h"
#include "bayes_filter_data.h"
#include "bayes_filter_initialize.h"
#include "bayes_filter_types.h"
#include "conv2stateno.h"
#include "fileManager.h"
#include "coder_array.h"
#include "stdio.h"
#include <algorithm>
#include <cmath>
#include <stdio.h>

// Function Definitions
//
// %%%%%%%%%%%%%%%%%%%%% BAYES FILTER %%%%%%%%%%%%%%%%%%%%%%%%
//
// Arguments    : double ts
//                const double obs[3]
//                cell_wrap_0 e_label[1]
// Return Type  : void
//
void bayes_filter(double ts, const double obs[3], cell_wrap_0 e_label[1])
{
    static const double sen_model[64]
    {
        0.0,    0.8511, 0.8511, 0.977,  0.9778, 0.9948, 0.994,  1.0,
        0.5282, 0.0,    0.5305, 0.5371, 0.534,  0.6079, 0.5388, 0.5861,
        0.5382, 0.5406, 0.0,    0.547,  0.5535, 0.5529, 0.62,   0.5982,
        0.5472, 0.546,  0.5503, 0.0,    0.6242, 0.6075, 0.5556, 0.5844,
        0.6441, 0.6325, 0.6298, 0.6764, 0.0,    0.5903, 0.6224, 0.5924,
        0.6972, 0.7402, 0.6838, 0.6466, 0.7391, 0.0,    0.6767, 0.6473,
        0.5948, 0.5833, 0.6292, 0.5543, 0.5536, 0.5498, 0.0,    0.5447,
        0.806,  0.7919, 0.7913, 0.7485, 0.6529, 0.6687, 0.6761, 0.0
    };
    static const char cv1[7] {'X', '_', '1', ',', 'X', '_', '2'};
    static const char cv2[7] {'X', '_', '1', ',', 'X', '_', '3'};
    static const char cv3[7] {'X', '_', '2', ',', 'X', '_', '1'};
    static const char b_cv[5] {'U', 'n', 'o', 'c', 'c'};
    FILE *b_NULL;
    FILE *filestar;
    coder::array<double, 1U> bigA;
    cell_wrap_0 g_label;
    cell_wrap_0 r;
    double x[12];
    double Po[8];
    double m[8];
    double b_bigA[3];
    double g_state;
    double s_state;
    double tim;
    int jj;
    int k;
    int numRead;
    signed char j_data[8];
    signed char fileid;
    boolean_T exitg1;
    boolean_T incompleteRead;
    if (!isInitialized_bayes_filter)
    {
        bayes_filter_initialize();
    }
    // number of sensors
    // Total number of occupancy states
    if (ts != 0.0)
    {
        fileid = coder::cfopen("rb");
        g_state = 0.0;
        // If formatSpec contains a combination of numeric and character specifiers,
        // then fscanf converts each character to its numeric equivalent. This
        // conversion occurs even when the format explicitly skips all numeric
        // values (for example, formatSpec is '%*d %s').
        bigA.set_size(0);
        numRead = 1;
        coder::getfilestar(static_cast<double>(fileid), &filestar, &incompleteRead);
        exitg1 = false;
        while ((!exitg1) && (numRead > 0))
        {
            jj = -1;
            numRead = fscanf(filestar, "%lf%n", &g_state, &jj);
            //numRead = fscanf_s(filestar, "%lf%n", &g_state, &jj);
            if (jj != -1)
            {
                numRead++;
            }
            incompleteRead = (numRead == 0);
            if (numRead > 0)
            {
                jj = bigA.size(0);
                bigA.set_size(bigA.size(0) + 1);
                bigA[jj] = g_state;
                incompleteRead = ((2 > numRead) || incompleteRead);
            }
            if (incompleteRead)
            {
                exitg1 = true;
            }
        }
        Po[0] = bigA[4];
        Po[1] = bigA[5];
        Po[2] = bigA[6];
        Po[3] = bigA[7];
        Po[4] = bigA[8];
        Po[5] = bigA[9];
        Po[6] = bigA[10];
        Po[7] = bigA[11];
        coder::cfclose(static_cast<double>(fileid));
        b_bigA[0] = bigA[1];
        b_bigA[1] = bigA[2];
        b_bigA[2] = bigA[3];
        conv2stateno(b_bigA, &s_state, &g_label);
        conv2stateno(obs, &g_state, &g_label);
        tim = bigA[0] + (ts - bigA[0]);
    }
    else
    {
        // first observtaion
        // duplicate for iterative update
        for (jj = 0; jj < 8; jj++)
        {
            Po[jj] = 0.125;
        }
        //  Each value is now 1/(number of states), so it all sums to one.
        //  %Po=Po/sum(sum(Po)) Pull out the indices at which Po achieves its max
        //  The best estimate of the true rho value
        tim = ts;
        conv2stateno(obs, &g_state, &g_label);
        s_state = g_state;
    }
    //    if (ts ~=0)
    //       if (time_taken < 30.0*sens_model(s_state,g_state)) %mark the tstate
    //       transition invalid if time taken by transition is too less
    //            g_state=s_state;
    //       end
    //    end
    // do recursive bayes
    // Call via
    // prior=0.5;
    // prior=rho_bayes_iter(obs,prior)
    // store the posterior to the prior.
    // likelihood
    //  look at each possible value of rho, assume that at the given value there
    //  is actual death, and get the likelihood of the observation e_state
    //  assuming 1-d gaussian noise
    for (jj = 0; jj < 8; jj++)
    {
        double likh;
        if (s_state == g_state)
        {
            //  Start State and Goal State are same
            likh = 1.0 - sen_model[jj + ((static_cast<int>(g_state) - 1) << 3)];
        }
        else
        {
            // start and goal are different % mean the state changed
            likh = 1.0 - sen_model[jj + ((static_cast<int>(g_state) - 1) << 3)];
        }
        // Each likelihood corresponds to single observation but for varying rho
        // possibility (Usually a univariate Gaussian Distribution)
        m[jj] = likh * 2.0 * Po[jj];
        //  Combine this likelihood with the prior
    }
    g_state = m[0];
    for (k = 0; k < 7; k++)
    {
        g_state += m[k + 1];
    }
    if (g_state > 0.0)
    {
        for (jj = 0; jj < 8; jj++)
        {
            Po[jj] = m[jj] / g_state;
        }
        // normalize this distribution to make it a proper probability distribution.
    }
    for (jj = 0; jj < 8; jj++)
    {
        if (Po[jj] <= 0.01)
        {
            Po[jj] = 0.01;
            // True liklihood is never 0
        }
    }
    if (!std::isnan(Po[0]))
    {
        numRead = 1;
    }
    else
    {
        numRead = 0;
        k = 2;
        exitg1 = false;
        while ((!exitg1) && (k < 9))
        {
            if (!std::isnan(Po[k - 1]))
            {
                numRead = k;
                exitg1 = true;
            }
            else
            {
                k++;
            }
        }
    }
    if (numRead == 0)
    {
        s_state = Po[0];
    }
    else
    {
        s_state = Po[numRead - 1];
        jj = numRead + 1;
        for (k = jj; k < 9; k++)
        {
            g_state = Po[k - 1];
            if (s_state < g_state)
            {
                s_state = g_state;
            }
        }
    }
    numRead = 0;
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj <= 8))
    {
        if (Po[jj - 1] == s_state)
        {
            numRead++;
            j_data[numRead - 1] = static_cast<signed char>(jj);
            if (numRead >= 8)
            {
                exitg1 = true;
            }
            else
            {
                jj++;
            }
        }
        else
        {
            jj++;
        }
    }
    //  Get the peak value; it's most likely occupancy state
    // Estimated state index
    if (j_data[0] == 1)
    {
        //  UO
        r.f1.size[0] = 1;
        r.f1.size[1] = 5;
        for (jj = 0; jj < 5; jj++)
        {
            r.f1.data[jj] = b_cv[jj];
        }
        e_label[0] = r;
    }
    else if (j_data[0] == 2)
    {
        //  X1
        r.f1.size[0] = 1;
        r.f1.size[1] = 3;
        r.f1.data[0] = 'X';
        r.f1.data[1] = '_';
        r.f1.data[2] = '1';
        e_label[0] = r;
    }
    else if (j_data[0] == 3)
    {
        //  X2
        r.f1.size[0] = 1;
        r.f1.size[1] = 3;
        r.f1.data[0] = 'X';
        r.f1.data[1] = '_';
        r.f1.data[2] = '2';
        e_label[0] = r;
    }
    else if (j_data[0] == 4)
    {
        //  X3
        r.f1.size[0] = 1;
        r.f1.size[1] = 3;
        r.f1.data[0] = 'X';
        r.f1.data[1] = '_';
        r.f1.data[2] = '3';
        e_label[0] = r;
    }
    else if (j_data[0] == 5)
    {
        //  X12
        r.f1.size[0] = 1;
        r.f1.size[1] = 7;
        for (jj = 0; jj < 7; jj++)
        {
            r.f1.data[jj] = cv1[jj];
        }
        e_label[0] = r;
    }
    else if (j_data[0] == 6)
    {
        //  X13
        r.f1.size[0] = 1;
        r.f1.size[1] = 7;
        for (jj = 0; jj < 7; jj++)
        {
            r.f1.data[jj] = cv2[jj];
        }
        e_label[0] = r;
    }
    else if (j_data[0] == 7)
    {
        //  X23
        r.f1.size[0] = 1;
        r.f1.size[1] = 7;
        for (jj = 0; jj < 7; jj++)
        {
            r.f1.data[jj] = cv3[jj];
        }
        e_label[0] = r;
    }
    else
    {
        //  X123
        r.f1.size[0] = 1;
        r.f1.size[1] = 11;
        for (jj = 0; jj < 11; jj++)
        {
            r.f1.data[jj] = cv[jj];
        }
        e_label[0] = r;
    }
    x[0] = tim;
    x[1] = obs[0];
    x[2] = obs[1];
    x[3] = obs[2];
    std::copy(&Po[0], &Po[8], &x[4]);
    fileid = coder::cfopen("wb");
    b_NULL = NULL;
    for (jj = 0; jj < 12; jj++)
    {
        coder::getfilestar(static_cast<double>(fileid), &filestar, &incompleteRead);
        if (!(filestar == b_NULL))
        {
            fprintf(filestar, "%4.4f\n", x[jj]);
            if (incompleteRead)
            {
                fflush(filestar);
            }
        }
    }
    coder::cfclose(static_cast<double>(fileid));
}

//
// File trailer for bayes_filter.cpp
//
// [EOF]
//
