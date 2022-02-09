function [P, R] = init_PR_states4(m,n,g,mm,action_no,adj)
  P=zeros((m*n),(m*n),action_no);
  fact=0.8;
  hi=fact*0.1;
  med=fact*0.05;
  lo=fact*0.01;
  ulo=fact*0.001;

    for i=1:5
        for j=6:16
            way=0;
            obsi=conv2stateobs4(i);
            obsj=conv2stateobs4(j);
            for q=1:length(obsj)
                if (obsj(q) == 1)
                    if (adj(i,q+1) == 1)
                        way=1;
                        break;
                    end
                end
            end
            adj(i,j)=way;%toX_dd
        end
    end

    for i=6:16
        for j=1:5
            way=0;
            obsi=conv2stateobs4(i);
            obsj=conv2stateobs4(j);
            for q=1:length(obsi)
                if (obsi(q) == 1)
                    if (adj(q+1,j) == 1)
                        way=1;
                        break;
                    end
                end
            end
            adj(i,j)=way;%toX_dd
        end
    end
    
    for i=6:16
        for j=6:16
            way=0;
            obsi=conv2stateobs4(i);
            obsj=conv2stateobs4(j);
            for q=1:length(obsi)
                if (obsi(q) == 1)
                    for r=1:length(obsj)
                        if (obsi(r) == 1)
                            if (adj(q+1,r+1) == 1)
                                way=1;
                                break;
                            end
                        end
                    end
                end
                if (way==1)
                    break;
                end
            end
            adj(i,j)=way;%toX_dd
        end
    end

  % Definition of Transition matrix P(:,:,1) associated to action 1(stay) and P(:,:,2) associated to action 1(go)
  for action=1:action_no
        if (action == 1)
            p_stay=mm.p_stay*1.4;
            if (p_stay > 1.0)
                p_stay=0.99;
            end
            p_go=1-p_stay; 
        else
            p_go=mm.p_go*1.4;
            if (p_go > 1.0)
                p_go=0.99;
            end
            p_stay=1-p_go;
        end

        for i=1:5
            for j=1:5
                if (i==j)
                    P(i,j,action)=p_stay;%self_loop % %World dynamics favor staying
                else
                    P(i,j,action)=p_go*hi*adj(i,j);%toX_d %World dynamics 
                end
            end
        end
        for j=6:11
            P(1,j,action)=p_go*hi*adj(1,j);%toX_dd %World dynamics %TBD: see that if both states have common index
        end
        for j=12:15
            P(1,j,action)=p_go*lo*adj(1,j);%toX_ddd %World dynamics %TBD: see that if both states have common index
        end
        P(1,16,action)=p_go*ulo*adj(1,16);%toX_dddd %World dynamics %TBD: see that if both states have common index                
        for i=2:5
            for j=6:11
                P(i,j,action)=p_go*med*adj(i,j);%toX_d %World dynamics %TBD: see that if both states have common index
            end
        end
        for i=2:5
            for j=12:15
                P(i,j,action)=p_go*lo*adj(i,j);%toX_d %World dynamics %TBD: see that if both states have common index
            end
        end
        for i=2:5
                P(i,16,action)=p_go*ulo*adj(i,16);%toX_d %World dynamics %TBD: see that if both states have common index
        end

        for i=6:11
            P(i,1,action)=p_go*hi*adj(i,1);%to Door %World dynamics %TBD: see that if both states have common index
        end
        for i=6:11
            for j=2:5
                P(i,j,action)=p_go*med*adj(i,j);%toX_d %World dynamics %TBD: see that if both states have common index
            end
        end
        for i=6:11
            for j=6:11
                if (i==j)
                    P(i,j,action)=p_stay;%self_loop % %World dynamics favor staying
                else
                    P(i,j,action)=p_go*hi*adj(i,j);%toX_dd %World dynamics
                end
            end
        end
        for i=6:11
            for j=12:15
                P(i,j,action)=p_go*med*adj(i,j);%toX_d %World dynamics %TBD: see that if both states have common index
            end
        end
        for i=6:11
            P(i,16,action)=p_go*med*adj(i,16);%to Door %World dynamics %TBD: see that if both states have common index
        end

        for i=12:15
            P(i,1,action)=p_go*lo*adj(i,1);%to Door %World dynamics %TBD: see that if both states have common index
        end
        for i=12:15
            for j=2:5
                P(i,j,action)=p_go*lo*adj(i,j);%toX_d %World dynamics %TBD: see that if both states have common index
            end
        end
        for i=12:15
            for j=6:11
                P(i,j,action)=p_go*med*adj(i,j);%toX_d %World dynamics %TBD: see that if both states have common index
            end
        end
        for i=12:15
            for j=12:15
                if (i==j)
                    P(i,j,action)=p_stay;%self_loop % %World dynamics favor staying
                else
                    P(i,j,action)=p_go*hi*adj(i,j);%toX_ddd %World dynamics
                end
            end
        end
        for i=12:15
            P(i,16,action)=p_go*hi*adj(i,16);%to Door %World dynamics %TBD: see that if both states have common index
        end

        P(16,1,action)=p_go*ulo*adj(16,1);%to Door %World dynamics %TBD: see that if both states have common index
        for j=2:5
            P(16,j,action)=p_go*lo*adj(16,j);%toX_d %World dynamics %TBD: see that if both states have common index
        end
        for j=6:11
            P(16,j,action)=p_go*med*adj(16,j);%toX_dd %World dynamics %TBD: see that if both states have common index
        end
        for j=12:15
            P(16,j,action)=p_go*hi*adj(16,j);%toX_ddd %World dynamics %TBD: see that if both states have common index
        end
        P(16,16,action)=p_stay;%self_loop % %World dynamics favor staying

        for i=1:16
            P(i,i,action)=P(i,i,action)+(1-sum(P(i,:,action))); 
        end

        P(g,:,action)=0.0;
        P(g,g,action)=1.0;
 end

 gen_reward=0.04; %What should be the general reward for all states
 R=zeros(m*n,action_no)+gen_reward;