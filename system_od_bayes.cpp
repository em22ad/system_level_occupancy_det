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
#include "bayes_filter4.h"
#include "bayes_filter4_terminate.h"
#include <fstream>
#include <vector>
#include <sstream>

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

vector<string> split(const string &s, char delim) {
	vector<string> result;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}

void save2csv(string filename, vector<int> x1v, vector<int> x2v, vector<int> x3v, vector<int> x4v)
{
	std::ofstream ofile;
	ofile.open(filename);
	int size = x1v.size();
	for (int i = 0; i < size; i++)
	{
		ofile << x1v[i]<<","<<x2v[i]<<","<<x3v[i]<<","<<x4v[i]<<"\n"; 
	}
	ofile.close();
}
void extract_obs(string filename, int *x1v, int *x2v, int *x3v, int *x4v, int& tot_obs)
{
	ifstream datafile(filename);

	//vector<double> ts;
	vector<int> x1;
	vector<int> x2;
	vector<int> x3;
	vector<int> x4;

	// Read the file;
	string line;
	char delimiter;

	if (datafile.is_open()) {
		//Read the file.
		vector<string> v;
		string vv;
		int ctr = 0;
		while (datafile.good())
		{
			datafile >> line; //>> delimiter >> dummys >> delimiter >> dummy >> delimiter >> temp >> delimiter >> adc1 >> delimiter >> adc2 >> delimiter >> pir;
			v = split(line, ',');
			//if (ctr == 0)
			//{
			//	//cout << line << "\n";
			//	//cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << "\n";
			//	//cout << v[0][3]<<"\n";
			//	vv.clear();
			//	vv.push_back(v[0][3]);
			//	//cout << vv << " " << v[1] << " " << v[2] << " " << v[3] << "\n";
			//}
			//else
			//{
			//	//cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << "\n";
			//}
			if (v.size() > 3)
			{
				//std::ostringstream oss;
				//oss << timeSinceEpoch;
				//{ oss.str(), std::stof(v[3]), std::stof(v[4]), std::stof(v[5]), std::stoi(v[6]) }
				//ts.push_back(std::stof(v[0]));
				if (ctr == 0)
					//x1.push_back(std::stof(vv));
					x1.push_back(std::stof(v[0]));
				else
					x1.push_back(std::stof(v[0]));

				x2.push_back(std::stof(v[1]));
				x3.push_back(std::stof(v[2]));
				x4.push_back(std::stof(v[3]));
			}
			ctr = ctr + 1;
			//if (ctr > 5000 - 1)
			//	break;
		}
		cout << "\nRecords read:" << x1.size() << endl;
		
		for (int i = 0; i < ctr; i++)
		{
			x1v[i] = x1[i];
			x2v[i] = x2[i];
			x3v[i] = x3[i];
			x4v[i] = x4[i];
		}
	}
	
	tot_obs = x1.size();

}

//
// Arguments    : void
// Return Type  : void
//
static void main_bayes_filter4()
{
  
  signed char dv[4];
  signed char e_obs[4];
  signed char period_tmp;
  
  signed char time_threshold = 50;

  int *x1v;
  int *x2v;
  int *x3v;
  int *x4v;
  int tot_obs=0;
  int OBSINDAY = 2880;
  x1v = (int *)calloc(OBSINDAY, sizeof(int));
  x2v = (int *)calloc(OBSINDAY, sizeof(int));
  x3v = (int *)calloc(OBSINDAY, sizeof(int));
  x4v = (int *)calloc(OBSINDAY, sizeof(int));
  vector<int> x1e;
  vector<int> x2e;
  vector<int> x3e;
  vector<int> x4e;

  extract_obs("2mar_catd.txt", x1v, x2v, x3v, x4v, tot_obs);

  dv[0] = 0; //sensor X1 output = 0
  dv[1] = 0; //sensor X2 output = 0
  dv[2] = 0; //sensor X3 output = 0 
  dv[3] = 0; //sensor X4 output = 0 
  period_tmp = 0;
  bayes_filter4(period_tmp, dv, time_threshold, e_obs);
  cout << int(dv[0]) << " " << int(dv[1]) << " " << int(dv[2]) << " " << int(dv[3]) << "\n";
  cout << int(e_obs[0]) << " " << int(e_obs[1]) << " " << int(e_obs[2]) << " " << int(e_obs[3]) << "\n\n";

  period_tmp = 30;
  for (int i = 0; i < tot_obs; i++)
  {
	  dv[0] = x1v[i]; //sensor X1 
	  dv[1] = x2v[i]; //sensor X2 
	  dv[2] = x3v[i]; //sensor X3 
	  dv[3] = x4v[i]; //sensor X4 
	  bayes_filter4(period_tmp, dv, time_threshold, e_obs);
	  cout << int(dv[0]) << " " << int(dv[1]) << " " << int(dv[2]) << " " << int(dv[3]) << "\n";
	  cout << int(e_obs[0]) << " " << int(e_obs[1]) << " " << int(e_obs[2]) << " " << int(e_obs[3]) << "\n\n";
	  x1e.push_back(int(e_obs[0]));
	  x2e.push_back(int(e_obs[1]));
	  x3e.push_back(int(e_obs[2]));
	  x4e.push_back(int(e_obs[3]));
  }
  save2csv("2mar_catd_est.txt", x1e, x2e, x3e, x4e);
}

#ifndef SYSTEM_OD_BAYES_INTEGRATION
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
#endif // SYSTEM_OD_BAYES_INTEGRATION

//
// File trailer for main.cpp
//
// [EOF]
//
