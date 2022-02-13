//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bayes_filter4.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 13-Feb-2022 02:24:51
//

// Include Files
#include "bayes_filter4.h"
#include "bayes_filter4_data.h"
#include "bayes_filter4_initialize.h"
#include "bayes_filter4_internal_types.h"
#include "conv2stateno4.h"
#include "fileManager.h"
#include "fscanf.h"
#include "isequal.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stdio.h>

// Function Definitions
//
// %%%%%%%%%%%%%%%%%%%%% BAYES FILTER %%%%%%%%%%%%%%%%%%%%%%%%
//  sens_model= [0    0.5282    0.5382    0.5472    0.6441    0.6972    0.5948
//  0.8060;
//      0.8511         0    0.5406    0.5460    0.6325    0.7402    0.5833
//      0.7919; 0.8511    0.5305         0    0.5503    0.6298    0.6838 0.6292
//      0.7913; 0.9770    0.5371    0.5470         0    0.6764    0.6466 0.5543
//      0.7485; 0.9778    0.5340    0.5535    0.6242         0    0.7391.5536
//      0.6529; 0.9948    0.6079    0.5529    0.6075    0.5903         0 0.5498
//      0.6687; 0.9940    0.5388    0.6200    0.5556    0.6224    0.6767 0
//      0.6761; 1000    0.5861    0.5982    0.5844    0.5924    0.6473 0.5447
//      0];
//
// Arguments    : signed char period
//                const signed char obs[4]
//                signed char time_thresh
//                signed char e_obs[4]
// Return Type  : void
//
void bayes_filter4(signed char period, const signed char obs[4],
                   signed char time_thresh, signed char e_obs[4])
{
  static const double dv1[4]{1, 0, 0, 0};
  static const double dv10[4]{0, 0, 1, 1};
  static const double dv11[4]{1, 1, 1, 0};
  static const double dv12[4]{1, 1, 0, 1};
  static const double dv13[4]{1, 0, 1, 1};
  static const double dv14[4]{0, 1, 1, 1};
  static const double dv2[4]{0, 1, 0, 0};
  static const double dv3[4]{0, 0, 1, 0};
  static const double dv4[4]{0, 0, 0, 1};
  static const double dv5[4]{1, 1, 0, 0};
  static const double dv6[4]{1, 0, 1, 0};
  static const double dv7[4]{1, 0, 0, 1};
  static const double dv8[4]{0, 1, 1, 0};
  static const double dv9[4]{0, 1, 0, 1};
  FILE *b_NULL;
  FILE *filestar;
  coder::array<double, 1U> data;
  cell_wrap_0 g_label;
  double sens_model[256];
  double x[22];
  double Po[16];
  double m[16];
  double dv[4];
  double lobs[4];
  double d;
  double g_state;
  double s_state;
  double times;
  int i;
  int idx;
  int jj;
  signed char jj_data[16];
  signed char fileid;
  signed char tim;
  signed char time_taken;
  boolean_T autoflush;
  boolean_T exitg1;
  if (!isInitialized_bayes_filter4) {
    bayes_filter4_initialize();
  }
  // number of sensors
  // Total number of occupancy states
  if (period != 0) {
    unsigned int ctr;
    fileid = coder::cfopen("last_iter4.txt", "rb");
    coder::b_fscanf(static_cast<double>(fileid), data);
    times = data[0];
    // 3:6
    lobs[0] = data[2];
    // 3:6
    lobs[1] = data[3];
    // 3:6
    lobs[2] = data[4];
    // 3:6
    lobs[3] = data[5];
    for (i = 0; i < 16; i++) {
      // 7:22
      Po[i] = data[i + 6];
    }
    coder::cfclose(static_cast<double>(fileid));
    s_state = 1;
    dv[0] = 0;
    dv[1] = 0;
    dv[2] = 0;
    dv[3] = 0;
    if (!coder::isequal(lobs, dv)) {
      if (coder::isequal(lobs, dv1)) {
        //  X1
        s_state = 2.0;
      } else if (coder::isequal(lobs, dv2)) {
        //  X2
        s_state = 3.0;
      } else if (coder::isequal(lobs, dv3)) {
        //  X3
        s_state = 4.0;
      } else if (coder::isequal(lobs, dv4)) {
        //  X4
        s_state = 5.0;
      } else if (coder::isequal(lobs, dv5)) {
        //  X12
        s_state = 6.0;
      } else if (coder::isequal(lobs, dv6)) {
        //  X13
        s_state = 7.0;
      } else if (coder::isequal(lobs, dv7)) {
        //  X14
        s_state = 8.0;
      } else if (coder::isequal(lobs, dv8)) {
        //  X23
        s_state = 9.0;
      } else if (coder::isequal(lobs, dv9)) {
        //  X24
        s_state = 10;
      } else if (coder::isequal(lobs, dv10)) {
        //  X34
        s_state = 11;
      } else if (coder::isequal(lobs, dv11)) {
        //  X123
        s_state = 12.0;
      } else if (coder::isequal(lobs, dv12)) {
        //  X124
        s_state = 13.0;
      } else if (coder::isequal(lobs, dv13)) {
        //  X134
        s_state = 14.0;
      } else if (coder::isequal(lobs, dv14)) {
        //  X234
        s_state = 15.0;
      } else {
        dv[0] = 1;
        dv[1] = 1;
        dv[2] = 1;
        dv[3] = 1;
        if (coder::isequal(lobs, dv)) {
          //  X1234
          s_state = 16.0;
        }
      }
    } else {
      //  UO
    }
    conv2stateno4(obs, &g_state, &g_label);
    time_taken = period;
    d = std::round(data[1] + static_cast<double>(period));
    if (d < 128.0) {
      if (d >= -128.0) {
        tim = static_cast<signed char>(d);
      } else {
        tim = MIN_int8_T;
      }
    } else if (d >= 128.0) {
      tim = MAX_int8_T;
    } else {
      tim = 0;
    }
    fileid = coder::cfopen("sens_model4.txt", "rb");
    coder::b_fscanf(static_cast<double>(fileid), data);
    ctr = 1U;
    for (i = 0; i < 16; i++) {
      for (jj = 0; jj < 16; jj++) {
        sens_model[i + (jj << 4)] = data[static_cast<int>(ctr + jj) - 1];
      }
      ctr += 16U;
    }
    coder::cfclose(static_cast<double>(fileid));
  } else {
    unsigned int ctr;
    // first observtaion
    times = 1;
    // duplicate for iterative update
    for (jj = 0; jj < 16; jj++) {
      Po[jj] = 0.0625;
    }
    //  Each value is now 1/(number of states), so it all sums to one.
    //  %Po=Po/sum(sum(Po)) Pull out the indices at which Po achieves its max
    //  The best estimate of the true rho value
    tim = 0;
    conv2stateno4(obs, &g_state, &g_label);
    s_state = g_state;
    time_taken = 0;
    fileid = coder::cfopen("sens_model4.txt", "rb");
    coder::b_fscanf(static_cast<double>(fileid), data);
    ctr = 1U;
    for (i = 0; i < 16; i++) {
      for (jj = 0; jj < 16; jj++) {
        sens_model[i + (jj << 4)] = data[static_cast<int>(ctr + jj) - 1];
      }
      ctr += 16U;
    }
    coder::cfclose(static_cast<double>(fileid));
    // sens_model=initialize_filter(sno,p_stay,p_move,adj);
  }
  if (period != 0) {
    d = std::round(times * static_cast<double>(time_taken));
    if (d < 128.0) {
      if (d >= -128.0) {
        time_taken = static_cast<signed char>(d);
      } else {
        time_taken = MIN_int8_T;
      }
    } else if (d >= 128.0) {
      time_taken = MAX_int8_T;
    } else {
      time_taken = 0;
    }
    d = std::round(static_cast<double>(time_thresh) *
                   sens_model[(static_cast<int>(s_state) +
                               ((static_cast<int>(g_state) - 1) << 4)) -
                              1]);
    if (d < 128.0) {
      if (d >= -128.0) {
        fileid = static_cast<signed char>(d);
      } else {
        fileid = MIN_int8_T;
      }
    } else if (d >= 128.0) {
      fileid = MAX_int8_T;
    } else {
      fileid = 0;
    }
    if (time_taken < fileid) {
      // mark the tstate transition invalid if time taken by transition is too
      // less g_state
      g_state = s_state;
      times += 0.05;
    } else {
      times = 1;
    }
  } else {
    times = 1;
  }
  // do recursive bayes
  // Call via
  // prior=0.5;
  // prior=rho_bayes_iter(obs,prior)
  // store the posterior to the prior.
  // likelihood
  //  look at each possible value of rho, assume that at the given value there
  //  is actual death, and get the likelihood of the observation e_state
  //  assuming 1-d gaussian noise
  for (i = 0; i < 16; i++) {
    if (s_state == g_state) {
      //  Start State and Goal State are same
      d = 1 - sens_model[i + ((static_cast<int>(g_state) - 1) << 4)];
    } else {
      // start and goal are different % mean the state changed
      d = 1 - sens_model[i + ((static_cast<int>(g_state) - 1) << 4)];
    }
    // Each likelihood corresponds to single observation but for varying state
    // possibility (Usually a univariate Gaussian Distribution)
    d *= Po[i];
    m[i] = d;
    //  Combine this likelihood with the prior
  }
  d = m[0];
  for (i = 0; i < 15; i++) {
    d += m[i + 1];
  }
  if (d > 0.0) {
    for (jj = 0; jj < 16; jj++) {
      Po[jj] = m[jj] / d;
    }
    // normalize this distribution to make it a proper probability distribution.
  }
  if (!std::isnan(Po[0])) {
    idx = 1;
  } else {
    idx = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 17)) {
      if (!std::isnan(Po[i - 1])) {
        idx = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }
  if (idx == 0) {
    s_state = Po[0];
    idx = 1;
  } else {
    s_state = Po[idx - 1];
    jj = idx + 1;
    for (i = jj; i < 17; i++) {
      d = Po[i - 1];
      if (s_state < d) {
        s_state = d;
        idx = i;
      }
    }
  }
  g_state = Po[0];
  for (i = 0; i < 15; i++) {
    g_state += Po[i + 1];
  }
  if (s_state / g_state > 0.7) {
    for (i = 0; i < 16; i++) {
      if (i + 1 != idx) {
        Po[i] *= 4.0;
      } else {
        Po[i] /= 1.5;
      }
    }
  }
  for (i = 0; i < 16; i++) {
	  if (Po[i] <= 0.05) {
		  Po[i] = 0.05;
		  // True liklihood is never 0
	  }
  }
  if (!std::isnan(Po[0])) {
    idx = 1;
  } else {
    idx = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 17)) {
      if (!std::isnan(Po[i - 1])) {
        idx = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }
  if (idx == 0) {
    s_state = Po[0];
  } else {
    s_state = Po[idx - 1];
    jj = idx + 1;
    for (i = jj; i < 17; i++) {
      d = Po[i - 1];
      if (s_state < d) {
        s_state = d;
      }
    }
  }
  idx = 0;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= 16)) {
    if (Po[jj - 1] == s_state) {
      idx++;
      jj_data[idx - 1] = static_cast<signed char>(jj);
      if (idx >= 16) {
        exitg1 = true;
      } else {
        jj++;
      }
    } else {
      jj++;
    }
  }
  //  Get the peak value; it's most likely occupancy state
  // Estimated state index
  if (jj_data[0] == 1) {
    //  UO
    e_obs[0] = 0;
    e_obs[1] = 0;
    e_obs[2] = 0;
    e_obs[3] = 0;
  } else if (jj_data[0] == 2) {
    //  X1
    e_obs[0] = 1;
    e_obs[1] = 0;
    e_obs[2] = 0;
    e_obs[3] = 0;
  } else if (jj_data[0] == 3) {
    //  X2
    e_obs[0] = 0;
    e_obs[1] = 1;
    e_obs[2] = 0;
    e_obs[3] = 0;
  } else if (jj_data[0] == 4) {
    //  X3
    e_obs[0] = 0;
    e_obs[1] = 0;
    e_obs[2] = 1;
    e_obs[3] = 0;
  } else if (jj_data[0] == 5) {
    //  X4
    e_obs[0] = 0;
    e_obs[1] = 0;
    e_obs[2] = 0;
    e_obs[3] = 1;
  } else if (jj_data[0] == 6) {
    //  X12
    e_obs[0] = 1;
    e_obs[1] = 1;
    e_obs[2] = 0;
    e_obs[3] = 0;
  } else if (jj_data[0] == 7) {
    //  X13
    e_obs[0] = 1;
    e_obs[1] = 0;
    e_obs[2] = 1;
    e_obs[3] = 0;
  } else if (jj_data[0] == 8) {
    //  X14
    e_obs[0] = 1;
    e_obs[1] = 0;
    e_obs[2] = 0;
    e_obs[3] = 1;
  } else if (jj_data[0] == 9) {
    //  X23
    e_obs[0] = 0;
    e_obs[1] = 1;
    e_obs[2] = 1;
    e_obs[3] = 0;
  } else if (jj_data[0] == 10) {
    //  X24
    e_obs[0] = 0;
    e_obs[1] = 1;
    e_obs[2] = 0;
    e_obs[3] = 1;
  } else if (jj_data[0] == 11) {
    //  X34
    e_obs[0] = 0;
    e_obs[1] = 0;
    e_obs[2] = 1;
    e_obs[3] = 1;
  } else if (jj_data[0] == 12) {
    //  X123
    e_obs[0] = 1;
    e_obs[1] = 1;
    e_obs[2] = 1;
    e_obs[3] = 0;
  } else if (jj_data[0] == 13) {
    //  X124
    e_obs[0] = 1;
    e_obs[1] = 1;
    e_obs[2] = 0;
    e_obs[3] = 1;
  } else if (jj_data[0] == 14) {
    //  X134
    e_obs[0] = 1;
    e_obs[1] = 0;
    e_obs[2] = 1;
    e_obs[3] = 1;
  } else if (jj_data[0] == 15) {
    //  X234
    e_obs[0] = 0;
    e_obs[1] = 1;
    e_obs[2] = 1;
    e_obs[3] = 1;
  } else {
    //  X1234
    e_obs[0] = 1;
    e_obs[1] = 1;
    e_obs[2] = 1;
    e_obs[3] = 1;
  }
  std::memset(&x[0], 0, 22U * sizeof(double));
  x[0] = times;
  x[1] = tim;
  x[2] = static_cast<double>(e_obs[0]);
  x[3] = static_cast<double>(e_obs[1]);
  x[4] = static_cast<double>(e_obs[2]);
  x[5] = static_cast<double>(e_obs[3]);
  std::copy(&Po[0], &Po[16], &x[6]);
  fileid = coder::cfopen("last_iter4.txt", "wb");
  b_NULL = NULL;
  for (i = 0; i < 22; i++) {
    coder::getfilestar(static_cast<double>(fileid), &filestar, &autoflush);
    if (!(filestar == b_NULL)) {
      fprintf(filestar, "%4.4f\n", x[i]);
      if (autoflush) {
        fflush(filestar);
      }
    }
  }
  coder::cfclose(static_cast<double>(fileid));
}

//
// File trailer for bayes_filter4.cpp
//
// [EOF]
//
