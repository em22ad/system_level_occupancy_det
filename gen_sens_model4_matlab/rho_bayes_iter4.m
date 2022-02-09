%Call via
%prior=0.5;
%prior=rho_bayes_iter(obs,prior)
function [Po,msg_type]=rho_bayes_iter4(sen_model,s_state,g_state, Po)   
    Pr=Po; %store the posterior to the prior.
    m=0*Pr;   
    %likelihood
    % look at each possible value of rho, assume that at the given value there is
    % actual death, and get the likelihood of the observation e_state assuming
    % 1-d gaussian noise
    msg_type=2;
    for i=1:length(Pr)
        if (s_state == g_state) % Start State and Goal State are same
            likh=1.0-sen_model(i,g_state);
            msg_type=1;
        else %start and goal are different % mean the state changed
            likh=1.0-sen_model(i,g_state); 
            msg_type=2;
        end
        m(i) = likh*1.0; %Each likelihood corresponds to single observation but for varying state possibility (Usually a univariate Gaussian Distribution)            
        m(i) = m(i) * Pr(i); % Combine this likelihood with the prior   
    end
    
    if (sum(m) > 0)
        Po=m/sum(m); %normalize this distribution to make it a proper probability distribution.
    end


    for i=1:length(Po)
        if (Po(i) <= 0.005)
            Po(i)=0.005; %True liklihood is never 0
        end
    end

    [v,idx]=max(Po);
    if ((v/sum(Po))>0.70)
        for i=1:length(Po)
            if (i ~= idx)
                Po(i)=Po(i)*2.0;
            else
                Po(i)=Po(i)/2.0; 
            end
        end
    end
    Po