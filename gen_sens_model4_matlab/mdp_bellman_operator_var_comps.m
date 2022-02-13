function [V, policy, D_detail, comps] = mdp_bellman_operator_var_comps(P, PR, discount, Vprev)


% mdp_bellman_operator Applies the Bellman operator on the value function Vprev
%                      Returns a new value function and a Vprev-improving policy
% Arguments ---------------------------------------------------------------
% Let S = number of states, A = number of actions
%   P(SxSxA) = transition matrix
%              P could be an array with 3 dimensions or 
%              a cell array (1xA), each cell containing a matrix (SxS) possibly sparse
%   PR(SxA) = reward matrix
%              PR could be an array with 2 dimensions or 
%              a sparse matrix
%   discount = discount rate, in ]0, 1]
%   Vprev(S) = value function
% Evaluation --------------------------------------------------------------
%   V(S)   = new value function
%   policy(S) = Vprev-improving policy

% MDPtoolbox: Markov Decision Processes Toolbox
% Copyright (C) 2009  INRA
% Redistribution and use in source and binary forms, with or without modification, 
% are permitted provided that the following conditions are met:
%    * Redistributions of source code must retain the above copyright notice, 
%      this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright notice, 
%      this list of conditions and the following disclaimer in the documentation 
%      and/or other materials provided with the distribution.
%    * Neither the name of the <ORGANIZATION> nor the names of its contributors 
%      may be used to endorse or promote products derived from this software 
%      without specific prior written permission.
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
% ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
% WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
% IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
% INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
% BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
% DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
% LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
% OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
% OF THE POSSIBILITY OF SUCH DAMAGE.
if iscell(P); S = size(P{1},1); else S = size(P,1); end;
if chk_discount01(discount) == 0
    disp('--------------------------------------------------------')
    disp('MDP Toolbox ERROR: Discount rate must be in ]0; 1]')
    disp('--------------------------------------------------------')
elseif size(Vprev,1) ~= S
    disp('--------------------------------------------------------')
    disp('MDP Toolbox ERROR: Vprev must have the same dimension as P')
    disp('--------------------------------------------------------')
else
    comps=0;
    if iscell(P)
        A=size(P,3);
        S=size(P,1);
        Dyn=zeros(S,S);
        for a=1:A  
            Dyn(:,:)=P(:,:,a);
            for s=1:S
                Q(:,a) = PR(:,a) + discount(:,a)*Dyn*Vprev;
            end
        end
    else
        A = size(P,3);
        S=size(P,1);
        Dyn=zeros(S,S);
        for a=1:A
            Dyn(:,:)=P(:,:,a);
            for s=1:S
                Q(s,a) = PR(s,a) + discount(s,a).*Dyn(s,:)*Vprev;
                %Q(S,1) = R(S,1) + discount*P(S,S,1) * Vprev(Sx1)
                if sum(Dyn(s,:)>0.0) > 1
                    comps=comps+sum(Dyn(s,:)>0.0);
                end
            end
        end

        D_detail=zeros(S,A);
        for s=1:S
            if (min(Q(s,:)) < 0)
                adv=-(min(Q(s,:)));
            else
                adv=0;
            end
            if (sum(Q(s,:)+adv) ~= 0)
                D_detail(s,:)=(adv+Q(s,:))./sum((Q(s,:)+adv));
            end
        end
    end
    [V, policy] = max(Q,[],2); %choose max for each S rows with dim (1xA) in Q (dim SxA) 
    %policy has Sx1 elements. Each element has the index of Q-col of max
    %value. Which represents a particular action.
end
