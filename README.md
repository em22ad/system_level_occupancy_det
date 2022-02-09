# system_level_occupancy_det
A Bayes Filter Based System Level Occupancy Detection Module. 

This branch is for layout2 that supports 4 sensors. There must exist four Type A sensors in the dataset. We thus define the Adjacency matrix for the dataset as follows:

&emsp; &emsp; Door &emsp; X1 &emsp; X2 &emsp; X3 &emsp; X4<br />
Door&emsp; 1 &emsp;&emsp; 0 &emsp;&emsp; 1 &emsp; 1  &emsp; 1<br />
X1&emsp;&emsp; 0 &emsp;&emsp; 1 &emsp;&emsp; 1 &emsp; 1 &emsp; 1<br />
X2&emsp;&emsp; 1 &emsp;&emsp; 1 &emsp;&emsp; 1 &emsp; 1 &emsp; 1<br />
X3&emsp;&emsp; 1 &emsp;&emsp; 1 &emsp;&emsp; 1 &emsp; 1 &emsp; 1<br />
X4&emsp;&emsp; 1 &emsp;&emsp; 1 &emsp;&emsp; 1 &emsp; 1 &emsp; 1<br />

First we initialize the Bayes filter by generating the sensor model matrix file by executing the following script wihtin the folder titled "gen_sens_model4_matlab":

initialize_filter4(4,0.2,0.8,[1 0 1 1 1;0 1 1 1 1;1 1 1 1 1;1 1 1 1 1;1 1 1 1 1])<br /><br />
Above Matlab command will create a sensor model file called sens_model.txt in the main directory for our C++ bayes filter module.

First argument: 4 represents the total number of sensors (Door is always considered the first row and column of the adjacency matrix). Multiple entrances/exits to the observed space are dealt as a single "Door".<br />
Second argument: 0.2 is the expected probability for human subjects to stay where they are until the next observation is collected.<br /> 
Third argument: 0.8 is the probability for them to move around.<br />
Fourth argument: The adjacency matrix between sensors and entrances as decribed above.<br />
 
A Visual studio C++ 2017 solution is present in the main repo directory. The file bayes_filter3.cpp has the main() function. 

Please follow the directions below to understand the code flow and module usage.

1. Find the function "main_bayes_filter4()" within the bayes_filter4.cpp file.
2. This function demonstrates the use of interface function bayes_filter4(double period_elapsed, double dv[3], double time_threshold, double estimated_obs[3])
3. Input 1: double period_elapsed: This is the number of seconds elapsed since the last observation. This must be set to 0 for the first observations. This indicates to the function bayes_filter3 that this is the first observation. Later observations can be sent with period > 0.
4. Input 2: double dv[4]. Here dv[0] represents the digital computed output of SLEEPIR sensor X1 (0 or 1). Similarly, dv[1] represents sensor X2 output, dv[2] represents sensor X3 output and dv[3] represents sensor X4. We assume for here that there are only 4 sensors in the system.
5. Output: double e_obs[4] contains the occupancy state. For three sensors X1, X2, X3, X4 variables represent their occupancy status [bool X1, bool X2, bool X3, bool X4]. 
6. You may notice that the filter estimates lag behind the observations from the sensors. This is due to certain parameters within the filter. You can adjust the double time_threshold variable to reduce or increase this lag. Increasing the variable will filter more and may filter even valid observations. Reducing the value may make the filter more responsive but this will allow noise to pass through. 
7. Feel free to contact author via email emaad22@tamu.edu for additional explanation and/or zoom meeting. 
