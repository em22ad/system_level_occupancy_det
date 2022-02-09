//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 09-Feb-2022 08:07:09
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include Files
#include <iostream>
#include "main.h"
#include "bayes_filter4.h"
#include "bayes_filter4_terminate.h"

using namespace std;

// Function Declarations
static void argInit_1x4_real_T(double result[4]);

static double argInit_real_T();

static void main_bayes_filter4();

// Function Definitions
//
// Arguments    : double result[4]
// Return Type  : void
//
static void argInit_1x4_real_T(double result[4])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 4; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_bayes_filter4()
{
  double dv[4];
  double e_obs[4];
  double period_tmp;

  double time_threshold = 40;


  dv[0] = 0; //sensor X1 output = 0
  dv[1] = 0; //sensor X2 output = 0
  dv[2] = 0; //sensor X3 output = 0 
  dv[3] = 0; //sensor X4 output = 0 
  period_tmp = 0;
  bayes_filter4(period_tmp, dv, time_threshold, e_obs);
  cout << e_obs[0] << " " << e_obs[1] << " " << e_obs[2] << " " << e_obs[3] << "\n";

  dv[0] = 0; //sensor X1 output = 0
  dv[1] = 0; //sensor X2 output = 0
  dv[2] = 0; //sensor X3 output = 0 
  dv[3] = 0; //sensor X4 output = 0 
  period_tmp = 30;
  bayes_filter4(period_tmp, dv, time_threshold, e_obs);
  cout << e_obs[0] << " " << e_obs[1] << " " << e_obs[2] << " " << e_obs[3] << "\n";

  //Noisy Obs
  dv[0] = 1; //sensor X1 output = 1
  dv[1] = 1; //sensor X2 output = 1
  dv[2] = 1; //sensor X3 output = 1 
  dv[3] = 1; //sensor X4 output = 1
  period_tmp = 30;
  bayes_filter4(period_tmp, dv, time_threshold, e_obs);
  cout << e_obs[0] << " " << e_obs[1] << " " << e_obs[2] << " " << e_obs[3] << "\n";

  dv[0] = 0; //sensor X1 output = 0
  dv[1] = 0; //sensor X2 output = 0
  dv[2] = 1; //sensor X3 output = 1
  dv[3] = 0; //sensor X4 output = 0 
  period_tmp = 30;
  bayes_filter4(period_tmp, dv, time_threshold, e_obs);
  cout << e_obs[0] << " " << e_obs[1] << " " << e_obs[2] << " " << e_obs[3] << "\n";

  dv[0] = 0; //sensor X1 output = 0
  dv[1] = 0; //sensor X2 output = 0
  dv[2] = 1; //sensor X3 output = 1
  dv[3] = 0; //sensor X4 output = 0 
  period_tmp = 30;
  bayes_filter4(period_tmp, dv, time_threshold, e_obs);
  cout << e_obs[0] << " " << e_obs[1] << " " << e_obs[2] << " " << e_obs[3] << "\n";

  dv[0] = 0; //sensor X1 output = 0
  dv[1] = 0; //sensor X2 output = 0
  dv[2] = 1; //sensor X3 output = 1
  dv[3] = 0; //sensor X4 output = 0 
  period_tmp = 35;
  bayes_filter4(period_tmp, dv, time_threshold, e_obs);
  cout << e_obs[0] << " " << e_obs[1] << " " << e_obs[2] << " " << e_obs[3] << "\n";

  dv[0] = 0; //sensor X1 output = 0
  dv[1] = 0; //sensor X2 output = 0
  dv[2] = 1; //sensor X3 output = 1 
  dv[3] = 0; //sensor X4 output = 0 
  period_tmp = 30;
  bayes_filter4(period_tmp, dv, time_threshold, e_obs);
  cout << e_obs[0] << " " << e_obs[1] << " " << e_obs[2] << " " << e_obs[3] << "\n";

  dv[0] = 0; //sensor X1 output = 0
  dv[1] = 0; //sensor X2 output = 0
  dv[2] = 1; //sensor X3 output = 1
  dv[3] = 0; //sensor X4 output = 0
  period_tmp = 35;
  bayes_filter4(period_tmp, dv, time_threshold, e_obs);
  cout << e_obs[0] << " " << e_obs[1] << " " << e_obs[2] << " " << e_obs[3] << "\n";

  dv[0] = 0; //sensor X1 output = 0
  dv[1] = 0; //sensor X2 output = 0
  dv[2] = 1; //sensor X3 output = 1
  dv[3] = 0; //sensor X4 output = 0
  period_tmp = 35;
  bayes_filter4(period_tmp, dv, time_threshold, e_obs);
  cout << e_obs[0] << " " << e_obs[1] << " " << e_obs[2] << " " << e_obs[3] << "\n";

  dv[0] = 0; //sensor X1 output = 0
  dv[1] = 0; //sensor X2 output = 0
  dv[2] = 1; //sensor X3 output = 1
  dv[3] = 0; //sensor X4 output = 0
  period_tmp = 35;
  bayes_filter4(period_tmp, dv, time_threshold, e_obs);
  cout << e_obs[0] << " " << e_obs[1] << " " << e_obs[2] << " " << e_obs[3] << "\n";

  dv[0] = 0; //sensor X1 output = 0
  dv[1] = 0; //sensor X2 output = 0
  dv[2] = 1; //sensor X3 output = 1
  dv[3] = 0; //sensor X4 output = 0
  period_tmp = 35;
  bayes_filter4(period_tmp, dv, time_threshold, e_obs);
  cout << e_obs[0] << " " << e_obs[1] << " " << e_obs[2] << " " << e_obs[3] << "\n";

  dv[0] = 0; //sensor X1 output = 0
  dv[1] = 0; //sensor X2 output = 0
  dv[2] = 1; //sensor X3 output = 1
  dv[3] = 0; //sensor X4 output = 0
  period_tmp = 35;
  bayes_filter4(period_tmp, dv, time_threshold, e_obs);
  cout << e_obs[0] << " " << e_obs[1] << " " << e_obs[2] << " " << e_obs[3] << "\n";

  dv[0] = 0; //sensor X1 output = 0
  dv[1] = 0; //sensor X2 output = 0
  dv[2] = 1; //sensor X3 output = 1
  dv[3] = 0; //sensor X4 output = 0
  period_tmp = 35;
  bayes_filter4(period_tmp, dv, time_threshold, e_obs);
  cout << e_obs[0] << " " << e_obs[1] << " " << e_obs[2] << " " << e_obs[3] << "\n";
  //bayes_filter4(period_tmp, dv, period_tmp, e_obs);
}

//
// Arguments    : int argc
//                char **argv
// Return Type  : int
//
int main(int, char **)
{
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  main_bayes_filter4();
  // Terminate the application.
  // You do not need to do this more than one time.
  bayes_filter4_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
