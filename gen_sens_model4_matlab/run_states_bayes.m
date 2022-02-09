function [P_ana, R, Amap]=run_states_bayes(goal, m, n, P, R, discount,mm)
%mdp_check(P,R)
[P_ana, R, Amap] = mdp_value_iteration_bayes_enh(goal, mm, m, n, P, R, discount);