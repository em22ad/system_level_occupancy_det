function initialize_filter4(sens_no,p_stay,p_move,adj)
m=(2^sens_no);%8;
n=1;
%start=[2 2];
action_no=2;%self-loop (Stay), out-going (Go to other room)
mm.p_stay=p_stay;%0.2;
mm.p_go=p_move;%0.8;
%%%%%%%%%%%%%%%%%%%%% PRECOMPUTE LIKLIHOOD %%%%%%%%%%%%%%%%%%%%%%
sen_model=zeros(m*n,m*n);% for staying at same place it takes 0 seconds sen_model(start_state,goal_state)
%define a static rho
discount=zeros(m,action_no)+0.95; %initialize flat discount plane
%set each state as a goal
goals=1:m;
for i=1:length(goals) %goal loop
    g=i;
    [P,R]=init_PR_states4(m,n,g,mm,action_no,adj); 
    %Set higher goal state Reward
    R(g,:)=1.0;
    %Ban certain states
    %for i=1:8
    %    [P,R]=obstacleAt(3,P,R,D_state);
    %end
    %for i=2:9
    %    [P,R]=obstacleAt(5,P,R,D_state);
    %end
    for j=1:length(goals) %start loop
        if (i~=j)
            s=j;
            [P_ana,bR, Amap]=run_states_bayes(g,m,n,P,R,discount,mm); %Use optimal policy for now, we can use a sub-optimal or even non-feasible random policy
            [P_ana,st_idx]=convert2canon_fixed(P_ana,s,g);
            [P_bar,t]=get_Pbar_finite_fixed(P_ana,st_idx,g);
            %sen_model=[sen_model;P_bar];
            sen_model(s,g)=t;
        end
    end
end
sens_model=mat2gray(sen_model);
save_model('../sens_model4.txt',sens_model);