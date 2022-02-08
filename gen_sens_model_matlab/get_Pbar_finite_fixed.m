function [Pbar,t] = get_Pbar_finite_fixed(P_an,st_idx,g)
if (st_idx > g)
    st_idx=st_idx-1;
end
Q=P_an(2:size(P_an,1),2:size(P_an,2));
R=P_an(2:size(P_an,1),1:1);
I=eye(size(Q,1),size(Q,2));
N=inv(I-Q);
%Expected number of periods  before absorption to any absorbing state given that the chain intially began in the st_idx state.
t=sum(N(st_idx,:));
fact=1.0; %This factor will convert the long-term probability to actual time.
t=t*fact;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% F=I;
% %botright=Q;
% for i=1:ceil(2*t(1)) %assuming we start at state 1
%     F=F+(Q^i);
%     %botright=botright*Q
% end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%
NR=N*R;
Pbar=NR(st_idx,1:1);
% swMsg=0.9*(1-sum(Pbar));
% swoMsg=0.1*(1-sum(Pbar));
% Pbar(3)= swMsg;
% Pbar(4)= swoMsg;