function [P_ana,st_idx] = convert2canon_fixed(P_ana,start, goal)
P_copy=P_ana;
goal_idx=goal;
ar_all=goal_idx;
idx=find(ar_all == start);
if size(idx,2)==0
    st_idx=start;
else
    disp('convert2canon_fixed.m: Warning - Invalid Start State');
    st_idx=start;
end
P_ana(ar_all,:)=[];
NonAb2All=P_ana; %Non-absorbing to all non-absorbing states outgoing probs
P_ana(:,ar_all)=[];

P_new=eye(size(P_ana,1)+1,size(P_ana,2)+1);
P_new(2:size(P_ana,1)+1,2:size(P_ana,2)+1)=P_ana;

%D_state=[arR(1) arR(2) ar2(1) ar2(2) arR(3)]; %D_state(1) = Death with Msg, D_state(2) = Death wo Msg, D_state(3) = Success with Msg, D_state(4) = Success wo Msg D_state(5) = Death wo Msg wo reaching Goal 

P_new(2:end,1)=NonAb2All(:,ar_all);

P_ana=P_new;