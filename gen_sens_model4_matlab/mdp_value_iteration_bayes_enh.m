function [P_ana, bR, Amap] = mdp_value_iteration_bayes_enh(goal, mm, m, n, P, R, discount, epsilon, max_iter, V0)

global mdp_VERBOSE;

% check of arguments
if iscell(P)
    S = size(P{1},1);
else
    S = size(P,1); 
end

if chk_discount01(discount) == 0
    disp('--------------------------------------------------------')
    disp('MDP Toolbox ERROR: Discount rate must be in ]0; 1]')
    disp('--------------------------------------------------------')
elseif nargin > 7 && (epsilon <= 0)
    disp('--------------------------------------------------------')
    disp('MDP Toolbox ERROR: epsilon must be upper than 0')
    disp('--------------------------------------------------------')
elseif nargin > 8 && max_iter <= 0
    disp('--------------------------------------------------------')
    disp('MDP Toolbox ERROR: The maximum number of iteration must be upper than 0')
    disp('--------------------------------------------------------')
elseif nargin > 9 && size(V0,1) ~= S
    disp('--------------------------------------------------------')
    disp('MDP Toolbox ERROR: V0 must have the same dimension as P')
    disp('--------------------------------------------------------')
else  
    PR = mdp_computePR(P,R);
    S=size(P,1);
    % initialization of optional arguments
    if nargin < 10
        V0 = zeros(S,1);
    end
    if nargin < 8
        epsilon = 0.01; 
    end
    % compute a bound for the number of iterations
    if chk_discount01(discount) == 1
       computed_max_iter = mdp_value_iteration_bound_iter_var(P, R, discount, epsilon, V0);
    end   
    if nargin < 11
        if chk_discount01(discount) == 1
            max_iter = computed_max_iter;
        else
            max_iter = 1000;
        end
    else
        if chk_discount01(discount) == 1 && max_iter > computed_max_iter
            disp(['MDP Toolbox WARNING: max_iter is bounded by ' num2str(computed_max_iter,'%12.1f') ])
            max_iter = computed_max_iter;
        end
    end
    
    % computation of threshold of variation for V for an epsilon-optimal policy
    if chk_discount01(discount) == 0
        disc=mean(discount(find(discount~=0))); %calculate mean of discount over all states and actions while ignoring zeros
        thresh = epsilon * (1-disc)/disc;
    else 
        thresh = epsilon;
    end
    
    if mdp_VERBOSE
        disp('  Iteration    V_variation'); 
    end
    
    iter = 0;
    V = V0;
    is_done = false;
    V_profile=V;
    total_comps=0;
    while ~is_done
        iter = iter + 1;
        Vprev = V;
        
        [V, policy, D_detail, comps] = mdp_bellman_operator_var_comps(P,PR,discount,V);
        total_comps=total_comps+comps;%(comps-(ceil(sqrt(S)*2.0)-1.0));
        fprintf("\nmdp_value_iteration_var.m: Computations over iteration # %d: %d",iter,comps);
        variation = mdp_span(V - Vprev);
        if mdp_VERBOSE 
            disp(['      ' num2str(iter,'%5i') '         ' num2str(variation)]); 
        end
        if variation < thresh 
            is_done = true; 
            if mdp_VERBOSE 
                disp('MDP Toolbox: iterations stopped, epsilon-optimal policy found')
            end
        elseif iter == max_iter
            is_done = true; 
            if mdp_VERBOSE 
                disp('MDP Toolbox: iterations stopped by maximum number of iteration condition')
            end
        end
        V_profile=[V_profile V];
    end
end

[P_ana] = init_PR_gridworld_diag_border_pol_based(m,n,policy,goal, mm,P);

Amap=policy;
show_map(Amap,PR);

bR=PR;


fprintf("\nmdp_value_iteration_var.m: Total computations over %d iterations: %d",iter,total_comps);
