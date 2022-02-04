// system_od_bayes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "main.h"
#include "bayes_filter.h"
#include "bayes_filter_terminate.h"
#include "bayes_filter_types.h"
#include "bayes_filter_initialize.h"
#include "conv2stateno.h"
#include "fileManager.h"
#include "coder_array.h"

using namespace std;

// Function Declarations
static void argInit_1x3_real_T(double result[3]);

static double argInit_real_T();

static void main_bayes_filter();

// Function Definitions
//
// Arguments    : double result[3]
// Return Type  : void
//
static void argInit_1x3_real_T(double result[3])
{
    // Loop over the array to initialize each element.
    for (int idx1{ 0 }; idx1 < 3; idx1++)
    {
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
/*
 * Pi4 board, 4GHz
 * timestamp is the period for each node's detection
 * e.g.{
 *  timestamp:0,    [0,0,0,0]
 *  timestamp:40,   [0,1,1,0]
 * }
 *
 * delay { Pi delay test
 *  3: bayes_filter(timestamp, dv, *(cell_wrap_0(*)[1]) & e_label); < 10ms
 *  4: good
 *  5: good
 *  6: good
 * }
 *
 *
 **/
static void main_bayes_filter()
{
    cell_wrap_0 e_label;
    double dv[3];
    double timestamp;
    // Initialize function 'bayes_filter' input arguments.
    // Initialize function input argument 'obs'.
    // Call the entry-point 'bayes_filter'.
    //argInit_1x3_real_T(dv);
    dv[0] = 0; //sensor X1 output = 0
    dv[1] = 0; //sensor X2 output = 0
    dv[2] = 0; //sensor X3 output = 0
    //bool dv_out[3];
    //[UNOCC, X1, X2, X3, {X1,X2}, {X1,X3}, {X2,X3}, {X1,X2,X3}]
    // 0,     1,  1,  1,   1,      1,        1,       1
    //bayes_filter(timestamp, 3, dv, dv_out);
    timestamp = 0;
    bayes_filter(timestamp, dv, *(cell_wrap_0(*)[1]) & e_label);
    cout << e_label.f1.data <<"\n";

    dv[0] = 0; //sensor X1 output = 0
    dv[1] = 0; //sensor X2 output = 0
    dv[2] = 0; //sensor X3 output = 0
    timestamp = 30;
    bayes_filter(timestamp, dv, *(cell_wrap_0(*)[1]) & e_label);
    cout << e_label.f1.data <<"\n" ;

    dv[0] = 0; //sensor X1 output = 0
    dv[1] = 1; //sensor X2 output = 0
    dv[2] = 0; //sensor X3 output = 0
    timestamp = 60;
    bayes_filter(timestamp, dv, *(cell_wrap_0(*)[1]) & e_label);
    cout << e_label.f1.data <<"\n" ;

    dv[0] = 0; //sensor X1 output = 0
    dv[1] = 1; //sensor X2 output = 0
    dv[2] = 0; //sensor X3 output = 0
    timestamp = 90;
    bayes_filter(timestamp, dv, *(cell_wrap_0(*)[1]) & e_label);
    cout << e_label.f1.data <<"\n" ;

    dv[0] = 0; //sensor X1 output = 0
    dv[1] = 1; //sensor X2 output = 0
    dv[2] = 0; //sensor X3 output = 0
    timestamp = 120;
    bayes_filter(timestamp, dv, *(cell_wrap_0(*)[1]) & e_label);
    cout << e_label.f1.data <<"\n" ;

    dv[0] = 0; //sensor X1 output = 0
    dv[1] = 1; //sensor X2 output = 0
    dv[2] = 0; //sensor X3 output = 0
    timestamp = 150;
    bayes_filter(timestamp, dv, *(cell_wrap_0(*)[1]) & e_label);
    cout << e_label.f1.data <<"\n" ;

    dv[0] = 0; //sensor X1 output = 0
    dv[1] = 1; //sensor X2 output = 0
    dv[2] = 0; //sensor X3 output = 0
    timestamp = 180;
    bayes_filter(timestamp, dv, *(cell_wrap_0(*)[1]) & e_label);
    cout << e_label.f1.data <<"\n" ;

    dv[0] = 0; //sensor X1 output = 0
    dv[1] = 1; //sensor X2 output = 0
    dv[2] = 0; //sensor X3 output = 0
    timestamp = 210;
    bayes_filter(timestamp, dv, *(cell_wrap_0(*)[1]) & e_label);
    cout << e_label.f1.data << "\n";
    //bayes_filter(argInit_real_T(), dv, *(cell_wrap_0(*)[1]) & e_label);
}

#ifndef SYSTEM_OD_BAYES_INTEGRATION
int main(int, char **)
{
    main_bayes_filter();
    // Terminate the application.
    // You do not need to do this more than one time.
    bayes_filter_terminate();
    return 0;
}
#endif // SYSTEM_OD_BAYES_INTEGRATION

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
