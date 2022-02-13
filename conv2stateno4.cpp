//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: conv2stateno4.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 13-Feb-2022 02:24:51
//

// Include Files
#include "conv2stateno4.h"
#include "bayes_filter4_internal_types.h"

// Function Definitions
//
// Arguments    : const signed char obs[4]
//                double *state
//                cell_wrap_0 *g_label
// Return Type  : void
//
void conv2stateno4(const signed char obs[4], double *state,
                   cell_wrap_0 *g_label)
{
  static const char cv11[15]{'X', '_', '1', ',', 'X', '_', '2', ',',
                             'X', '_', '3', ',', 'X', '_', '4'};
  static const char cv10[11]{'X', '_', '2', ',', 'X', '_',
                             '3', ',', 'X', '_', '4'};
  static const char cv7[11]{'X', '_', '1', ',', 'X', '_',
                            '2', ',', 'X', '_', '3'};
  static const char cv8[11]{'X', '_', '1', ',', 'X', '_',
                            '2', ',', 'X', '_', '4'};
  static const char cv9[11]{'X', '_', '1', ',', 'X', '_',
                            '3', ',', 'X', '_', '4'};
  static const char cv1[7]{'X', '_', '1', ',', 'X', '_', '2'};
  static const char cv2[7]{'X', '_', '1', ',', 'X', '_', '3'};
  static const char cv3[7]{'X', '_', '1', ',', 'X', '_', '4'};
  static const char cv4[7]{'X', '_', '2', ',', 'X', '_', '3'};
  static const char cv5[7]{'X', '_', '2', ',', 'X', '_', '4'};
  static const char cv6[7]{'X', '_', '3', ',', 'X', '_', '4'};
  static const char cv[5]{'U', 'n', 'o', 'c', 'c'};
  static const signed char iv[4]{1, 0, 0, 0};
  static const signed char iv1[4]{0, 1, 0, 0};
  static const signed char iv10[4]{1, 1, 1, 0};
  static const signed char iv11[4]{1, 1, 0, 1};
  static const signed char iv12[4]{1, 0, 1, 1};
  static const signed char iv13[4]{0, 1, 1, 1};
  static const signed char iv2[4]{0, 0, 1, 0};
  static const signed char iv3[4]{0, 0, 0, 1};
  static const signed char iv4[4]{1, 1, 0, 0};
  static const signed char iv5[4]{1, 0, 1, 0};
  static const signed char iv6[4]{1, 0, 0, 1};
  static const signed char iv7[4]{0, 1, 1, 0};
  static const signed char iv8[4]{0, 1, 0, 1};
  static const signed char iv9[4]{0, 0, 1, 1};
  cell_wrap_0 r;
  int b_state;
  int k;
  boolean_T exitg1;
  boolean_T p;
  b_state = 1;
  g_label->f1.size[0] = 1;
  g_label->f1.size[1] = 5;
  for (k = 0; k < 5; k++) {
    g_label->f1.data[k] = cv[k];
  }
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 4)) {
    if (obs[k] != 0) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (p) {
    //  UO
    r.f1.size[0] = 1;
    r.f1.size[1] = 5;
    for (k = 0; k < 5; k++) {
      r.f1.data[k] = cv[k];
    }
    *g_label = r;
  } else {
    p = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      if (obs[k] != iv[k]) {
        p = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (p) {
      //  X1
      b_state = 2;
      r.f1.size[0] = 1;
      r.f1.size[1] = 3;
      r.f1.data[0] = 'X';
      r.f1.data[1] = '_';
      r.f1.data[2] = '1';
      *g_label = r;
    } else {
      p = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (obs[k] != iv1[k]) {
          p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
      if (p) {
        //  X2
        b_state = 3;
        r.f1.size[0] = 1;
        r.f1.size[1] = 3;
        r.f1.data[0] = 'X';
        r.f1.data[1] = '_';
        r.f1.data[2] = '2';
        *g_label = r;
      } else {
        p = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 4)) {
          if (obs[k] != iv2[k]) {
            p = false;
            exitg1 = true;
          } else {
            k++;
          }
        }
        if (p) {
          //  X3
          b_state = 4;
          r.f1.size[0] = 1;
          r.f1.size[1] = 3;
          r.f1.data[0] = 'X';
          r.f1.data[1] = '_';
          r.f1.data[2] = '3';
          *g_label = r;
        } else {
          p = true;
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k < 4)) {
            if (obs[k] != iv3[k]) {
              p = false;
              exitg1 = true;
            } else {
              k++;
            }
          }
          if (p) {
            //  X4
            b_state = 5;
            r.f1.size[0] = 1;
            r.f1.size[1] = 3;
            r.f1.data[0] = 'X';
            r.f1.data[1] = '_';
            r.f1.data[2] = '4';
            *g_label = r;
          } else {
            p = true;
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k < 4)) {
              if (obs[k] != iv4[k]) {
                p = false;
                exitg1 = true;
              } else {
                k++;
              }
            }
            if (p) {
              //  X12
              b_state = 6;
              r.f1.size[0] = 1;
              r.f1.size[1] = 7;
              for (k = 0; k < 7; k++) {
                r.f1.data[k] = cv1[k];
              }
              *g_label = r;
            } else {
              p = true;
              k = 0;
              exitg1 = false;
              while ((!exitg1) && (k < 4)) {
                if (obs[k] != iv5[k]) {
                  p = false;
                  exitg1 = true;
                } else {
                  k++;
                }
              }
              if (p) {
                //  X13
                b_state = 7;
                r.f1.size[0] = 1;
                r.f1.size[1] = 7;
                for (k = 0; k < 7; k++) {
                  r.f1.data[k] = cv2[k];
                }
                *g_label = r;
              } else {
                p = true;
                k = 0;
                exitg1 = false;
                while ((!exitg1) && (k < 4)) {
                  if (obs[k] != iv6[k]) {
                    p = false;
                    exitg1 = true;
                  } else {
                    k++;
                  }
                }
                if (p) {
                  //  X14
                  b_state = 8;
                  r.f1.size[0] = 1;
                  r.f1.size[1] = 7;
                  for (k = 0; k < 7; k++) {
                    r.f1.data[k] = cv3[k];
                  }
                  *g_label = r;
                } else {
                  p = true;
                  k = 0;
                  exitg1 = false;
                  while ((!exitg1) && (k < 4)) {
                    if (obs[k] != iv7[k]) {
                      p = false;
                      exitg1 = true;
                    } else {
                      k++;
                    }
                  }
                  if (p) {
                    //  X23
                    b_state = 9;
                    r.f1.size[0] = 1;
                    r.f1.size[1] = 7;
                    for (k = 0; k < 7; k++) {
                      r.f1.data[k] = cv4[k];
                    }
                    *g_label = r;
                  } else {
                    p = true;
                    k = 0;
                    exitg1 = false;
                    while ((!exitg1) && (k < 4)) {
                      if (obs[k] != iv8[k]) {
                        p = false;
                        exitg1 = true;
                      } else {
                        k++;
                      }
                    }
                    if (p) {
                      //  X24
                      b_state = 10;
                      r.f1.size[0] = 1;
                      r.f1.size[1] = 7;
                      for (k = 0; k < 7; k++) {
                        r.f1.data[k] = cv5[k];
                      }
                      *g_label = r;
                    } else {
                      p = true;
                      k = 0;
                      exitg1 = false;
                      while ((!exitg1) && (k < 4)) {
                        if (obs[k] != iv9[k]) {
                          p = false;
                          exitg1 = true;
                        } else {
                          k++;
                        }
                      }
                      if (p) {
                        //  X34
                        b_state = 11;
                        r.f1.size[0] = 1;
                        r.f1.size[1] = 7;
                        for (k = 0; k < 7; k++) {
                          r.f1.data[k] = cv6[k];
                        }
                        *g_label = r;
                      } else {
                        p = true;
                        k = 0;
                        exitg1 = false;
                        while ((!exitg1) && (k < 4)) {
                          if (obs[k] != iv10[k]) {
                            p = false;
                            exitg1 = true;
                          } else {
                            k++;
                          }
                        }
                        if (p) {
                          //  X123
                          b_state = 12;
                          r.f1.size[0] = 1;
                          r.f1.size[1] = 11;
                          for (k = 0; k < 11; k++) {
                            r.f1.data[k] = cv7[k];
                          }
                          *g_label = r;
                        } else {
                          p = true;
                          k = 0;
                          exitg1 = false;
                          while ((!exitg1) && (k < 4)) {
                            if (obs[k] != iv11[k]) {
                              p = false;
                              exitg1 = true;
                            } else {
                              k++;
                            }
                          }
                          if (p) {
                            //  X124
                            b_state = 13;
                            r.f1.size[0] = 1;
                            r.f1.size[1] = 11;
                            for (k = 0; k < 11; k++) {
                              r.f1.data[k] = cv8[k];
                            }
                            *g_label = r;
                          } else {
                            p = true;
                            k = 0;
                            exitg1 = false;
                            while ((!exitg1) && (k < 4)) {
                              if (obs[k] != iv12[k]) {
                                p = false;
                                exitg1 = true;
                              } else {
                                k++;
                              }
                            }
                            if (p) {
                              //  X134
                              b_state = 14;
                              r.f1.size[0] = 1;
                              r.f1.size[1] = 11;
                              for (k = 0; k < 11; k++) {
                                r.f1.data[k] = cv9[k];
                              }
                              *g_label = r;
                            } else {
                              p = true;
                              k = 0;
                              exitg1 = false;
                              while ((!exitg1) && (k < 4)) {
                                if (obs[k] != iv13[k]) {
                                  p = false;
                                  exitg1 = true;
                                } else {
                                  k++;
                                }
                              }
                              if (p) {
                                //  X234
                                b_state = 15;
                                r.f1.size[0] = 1;
                                r.f1.size[1] = 11;
                                for (k = 0; k < 11; k++) {
                                  r.f1.data[k] = cv10[k];
                                }
                                *g_label = r;
                              } else {
                                p = true;
                                k = 0;
                                exitg1 = false;
                                while ((!exitg1) && (k < 4)) {
                                  if (obs[k] != 1) {
                                    p = false;
                                    exitg1 = true;
                                  } else {
                                    k++;
                                  }
                                }
                                if (p) {
                                  //  X1234
                                  b_state = 16;
                                  r.f1.size[0] = 1;
                                  r.f1.size[1] = 15;
                                  for (k = 0; k < 15; k++) {
                                    r.f1.data[k] = cv11[k];
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
// File trailer for conv2stateno4.cpp
//
// [EOF]
//
