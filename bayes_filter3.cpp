//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bayes_filter3.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 08-Feb-2022 06:06:06
//

// Include Files
#include "bayes_filter3.h"
#include "bayes_filter3_data.h"
#include "bayes_filter3_initialize.h"
#include "bayes_filter3_internal_types.h"
#include "conv2stateno.h"
#include "fileManager.h"
#include "fscanf.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>
#include <stdio.h>

// Function Definitions
//
// %%%%%%%%%%%%%%%%%%%%% BAYES FILTER %%%%%%%%%%%%%%%%%%%%%%%%
//  sens_model= [0    0.5282    0.5382    0.5472    0.6441    0.6972    0.5948
//  0.8060;
//      0.8511         0    0.5406    0.5460    0.6325    0.7402    0.5833
//      0.7919; 0.8511    0.5305         0    0.5503    0.6298    0.6838 0.6292
//      0.7913; 0.9770    0.5371    0.5470         0    0.6764    0.6466 0.5543
//      0.7485; 0.9778    0.5340    0.5535    0.6242         0    0.7391 0.5536
//      0.6529; 0.9948    0.6079    0.5529    0.6075    0.5903         0 0.5498
//      0.6687; 0.9940    0.5388    0.6200    0.5556    0.6224    0.6767 0
//      0.6761; 1.0000    0.5861    0.5982    0.5844    0.5924    0.6473 0.5447
//      0];
//
// Arguments    : double period
//                const double obs[3]
//                double time_thresh
//                double e_obs[3]
// Return Type  : void
//
void bayes_filter3(double period, const double obs[3], double time_thresh,
                   double e_obs[3])
{
  FILE *b_NULL;
  FILE *filestar;
  coder::array<double, 1U> data;
  cell_wrap_0 g_label;
  double sens_model[64];
  double x[13];
  double Po[8];
  double m[8];
  double b_data[3];
  double d;
  double g_state;
  double s_state;
  double tim;
  double time_taken;
  double times;
  int idx;
  int j;
  int jj;
  signed char j_data[8];
  signed char fileid;
  boolean_T autoflush;
  boolean_T exitg1;
  if (!isInitialized_bayes_filter3) {
    bayes_filter3_initialize();
  }
  // number of sensors
  // Total number of occupancy states
  if (period != 0.0) {
    unsigned int ctr;
    fileid = coder::cfopen("last_iter.txt", "rb");
    coder::b_fscanf(static_cast<double>(fileid), data);
    times = data[0];
    Po[0] = data[5];
    Po[1] = data[6];
    Po[2] = data[7];
    Po[3] = data[8];
    Po[4] = data[9];
    Po[5] = data[10];
    Po[6] = data[11];
    Po[7] = data[12];
    coder::cfclose(static_cast<double>(fileid));
    b_data[0] = data[2];
    b_data[1] = data[3];
    b_data[2] = data[4];
    conv2stateno(b_data, &s_state, &g_label);
    conv2stateno(obs, &g_state, &g_label);
    time_taken = period;
    tim = data[1] + period;
    fileid = coder::cfopen("sens_model.txt", "rb");
    coder::b_fscanf(static_cast<double>(fileid), data);
    ctr = 1U;
    for (jj = 0; jj < 8; jj++) {
      for (j = 0; j < 8; j++) {
        sens_model[jj + (j << 3)] = data[static_cast<int>(ctr + j) - 1];
      }
      ctr += 8U;
    }
    coder::cfclose(static_cast<double>(fileid));
  } else {
    unsigned int ctr;
    // first observtaion
    times = 1.0;
    // duplicate for iterative update
    for (jj = 0; jj < 8; jj++) {
      Po[jj] = 0.125;
    }
    //  Each value is now 1/(number of states), so it all sums to one.
    //  %Po=Po/sum(sum(Po)) Pull out the indices at which Po achieves its max
    //  The best estimate of the true rho value
    tim = 0.0;
    conv2stateno(obs, &g_state, &g_label);
    s_state = g_state;
    time_taken = 0.0;
    fileid = coder::cfopen("sens_model.txt", "rb");
    coder::b_fscanf(static_cast<double>(fileid), data);
    ctr = 1U;
    for (jj = 0; jj < 8; jj++) {
      for (j = 0; j < 8; j++) {
        sens_model[jj + (j << 3)] = data[static_cast<int>(ctr + j) - 1];
      }
      ctr += 8U;
    }
    coder::cfclose(static_cast<double>(fileid));
    // sens_model=initialize_filter(sno,p_stay,p_move,adj);
  }
  //  times*time_taken
  //  time_thresh*sens_model(s_state,g_state)
  //  s_state
  //  g_state
  if ((period != 0.0) &&
      (times * time_taken <
       time_thresh * sens_model[(static_cast<int>(s_state) +
                                 ((static_cast<int>(g_state) - 1) << 3)) -
                                1])) {
    // mark the tstate transition invalid if time taken by transition is too
    // less g_state
    g_state = s_state;
    times += 0.05;
  } else {
    times = 1.0;
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
  for (jj = 0; jj < 8; jj++) {
    if (s_state == g_state) {
      //  Start State and Goal State are same
      d = 1.0 - sens_model[jj + ((static_cast<int>(g_state) - 1) << 3)];
    } else {
      // start and goal are different % mean the state changed
      d = 1.0 - sens_model[jj + ((static_cast<int>(g_state) - 1) << 3)];
    }
    // Each likelihood corresponds to single observation but for varying state
    // possibility (Usually a univariate Gaussian Distribution)
    d *= Po[jj];
    m[jj] = d;
    //  Combine this likelihood with the prior
  }
  d = m[0];
  for (j = 0; j < 7; j++) {
    d += m[j + 1];
  }
  if (d > 0.0) {
    for (jj = 0; jj < 8; jj++) {
      Po[jj] = m[jj] / d;
    }
    // normalize this distribution to make it a proper probability distribution.
  }
  for (jj = 0; jj < 8; jj++) {
    if (Po[jj] <= 0.1) {
      Po[jj] = 0.2;
      // True liklihood is never 0
    }
  }
  // Po
  if (!std::isnan(Po[0])) {
    idx = 1;
  } else {
    idx = 0;
    j = 2;
    exitg1 = false;
    while ((!exitg1) && (j < 9)) {
      if (!std::isnan(Po[j - 1])) {
        idx = j;
        exitg1 = true;
      } else {
        j++;
      }
    }
  }
  if (idx == 0) {
    time_taken = Po[0];
  } else {
    time_taken = Po[idx - 1];
    jj = idx + 1;
    for (j = jj; j < 9; j++) {
      d = Po[j - 1];
      if (time_taken < d) {
        time_taken = d;
      }
    }
  }
  idx = 0;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= 8)) {
    if (Po[jj - 1] == time_taken) {
      idx++;
      j_data[idx - 1] = static_cast<signed char>(jj);
      if (idx >= 8) {
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
  if (j_data[0] == 1) {
    //  UO
    e_obs[0] = 0.0;
    e_obs[1] = 0.0;
    e_obs[2] = 0.0;
  } else if (j_data[0] == 2) {
    //  X1
    e_obs[0] = 1.0;
    e_obs[1] = 0.0;
    e_obs[2] = 0.0;
  } else if (j_data[0] == 3) {
    //  X2
    e_obs[0] = 0.0;
    e_obs[1] = 1.0;
    e_obs[2] = 0.0;
  } else if (j_data[0] == 4) {
    //  X3
    e_obs[0] = 0.0;
    e_obs[1] = 0.0;
    e_obs[2] = 1.0;
  } else if (j_data[0] == 5) {
    //  X1X2
    e_obs[0] = 1.0;
    e_obs[1] = 1.0;
    e_obs[2] = 0.0;
  } else if (j_data[0] == 6) {
    //  X1X3
    e_obs[0] = 1.0;
    e_obs[1] = 0.0;
    e_obs[2] = 1.0;
  } else if (j_data[0] == 7) {
    //  X2X3
    e_obs[0] = 0.0;
    e_obs[1] = 1.0;
    e_obs[2] = 1.0;
  } else {
    //  X123
    e_obs[0] = 1.0;
    e_obs[1] = 1.0;
    e_obs[2] = 1.0;
  }
  x[0] = times;
  x[1] = tim;
  x[2] = e_obs[0];
  x[3] = e_obs[1];
  x[4] = e_obs[2];
  std::copy(&Po[0], &Po[8], &x[5]);
  fileid = coder::cfopen("last_iter.txt", "wb");
  b_NULL = NULL;
  for (jj = 0; jj < 13; jj++) {
    coder::getfilestar(static_cast<double>(fileid), &filestar, &autoflush);
    if (!(filestar == b_NULL)) {
      fprintf(filestar, "%4.4f\n", x[jj]);
      if (autoflush) {
        fflush(filestar);
      }
    }
  }
  coder::cfclose(static_cast<double>(fileid));
}

//
// File trailer for bayes_filter3.cpp
//
// [EOF]
//
