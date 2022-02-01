# system_level_occupancy_det
A Bayes Filter Based System Level Occupancy Detection Module. 

A Visual studio C++ 2017 solution is present in the repo. The file system_od_bayes.cpp has the main() function. 

Please follow the directions below to understand the code flow and module usage.

1. Find the function "static void main_bayes_filter()" within the system_od_bayes.cpp file.
2. This function demonstrates the use of interface function bayes_filter(double timestamp, double dv[3], *(cell_wrap_0(*)[1]) & e_label)
3. Input 1: double timestamp: This is a timestamp in seconds. First observation must send in timestamp=0. This indicates to the function bayes_filter that this is the first observation. Later observations can be sent with timestamps > 0.
4. Input 2: double dv[3]. Here dv[0] represents the digital computed output of SLEEPIR sensor X1 (0 or 1). Similarly, dv[1] represents sensor X2 output and dv[2] represents sensor X3 output. We assume for now that there are only 3 sensors in the system.
5. Output: e_label.f1.data contains the label of the occupancy state. For three sensors X1, X2 and X3, The filter estimates one of the following outputs 
                                                              [UNOCC, X1, X2, X3, {X1,X2}, {X1,X3}, {X2,X3}, {X1,X2,X3}]
Above set consists of all possible occupancy states. UNOCC is a short form for "Un-occupied". This is the only state that represents un-occupancy. Remaining labels represent occupied states.
6. You may notice that the filter estimates lag behind the observtaions from the sensors. This is due to certain parameters within the filter. These parameters are being tuned at present.
7. The Bayesian filter uses an adjacency matrix which tells it which of the sensors among X1, X2 and X3 are present in adjacent rooms. Presently the filter is tuned for Lab Dataset map. For any other maps, a sensor adjacency matrix will be required by the filter.
8. Feel free to contact me via email emaad22@tamu.edu for additional explanation and/or zoom meeting. 
