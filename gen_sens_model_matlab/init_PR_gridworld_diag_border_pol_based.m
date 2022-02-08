function [P] = init_PR_gridworld_diag_border_pol_based(m,n,pol,goal,mm,P_dyn)

P=zeros((m*n),(m*n));


for i = 1:(m*n)
    if (pol(i) == 1) %stay  
        for j = 1:(m*n)
            P(i,j) = P_dyn(i,j,1);
        end
    elseif (pol(i)==2) %go
        for j = 1:(m*n)
            P(i,j) = P_dyn(i,j,2);
        end
    end
end

% P(goal,:)=0.0;
% P(goal,goal)=1.0;
