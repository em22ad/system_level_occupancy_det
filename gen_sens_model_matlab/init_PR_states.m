function [P, R] = init_PR_states(m,n,g,mm,action_no,adj)
  P(:,:,1)=zeros((m*n),(m*n));
  % Definition of Transition matrix P(:,:,1) associated to action 1(stay) and
  p_stay=mm.p_stay*1.4;
  if (p_stay > 1.0)
      p_stay=0.99;
  end
  p_go=1-p_stay;
  % stay from UO
  P(1,1,1)=p_stay;%self_loop % %World dynamics favor staying
  P(1,2,1)=p_go*0.2*adj(1,2);%toX1 % %World dynamics
  P(1,3,1)=p_go*0.2*adj(1,3);%toX2 % %World dynamics
  P(1,4,1)=p_go*0.2*adj(1,4);%toX3 % %World dynamics
  P(1,5,1)=p_go*0.125*double(adj(1,2)&&adj(1,3));%toX12 % %World dynamics
  P(1,6,1)=p_go*0.125*double(adj(1,2)&&adj(1,4));%toX13 % %World dynamics
  P(1,7,1)=p_go*0.1*double(adj(1,3)&&adj(1,4));%toX23 % %World dynamics
  P(1,8,1)=p_go*0.05*double(adj(1,2)&&adj(1,3)&&adj(1,4));%toX123 % %World dynamics
  P(1,1,1)=P(1,1,1)+(1-sum(P(1,:,1)));
  % stay from X1
  P(2,1,1)=p_go*0.2*adj(2,1);%toUO %World dynamics
  P(2,2,1)=p_stay;%self_loop % %World dynamics favor staying
  P(2,3,1)=p_go*0.2*adj(2,3);%toX2 % %World dynamics
  P(2,4,1)=p_go*0.2*adj(2,4);%toX3 % %World dynamics
  P(2,5,1)=p_go*0.125*double(adj(2,2)&&adj(2,3));%toX12 % %World dynamics
  P(2,6,1)=p_go*0.1*double(adj(2,2)&&adj(2,4));%toX13 % %World dynamics
  P(2,7,1)=p_go*0.125*double(adj(2,3)&&adj(2,4));%toX23 % %World dynamics
  P(2,8,1)=p_go*0.05*double(adj(2,2)&&adj(2,3)&&adj(2,4));%toX123 % %World dynamics
  P(2,1,1)=P(2,1,1)+(1-sum(P(2,:,1)));
  % stay from X2
  P(3,1,1)=p_go*0.2*adj(3,1);%toUO %World dynamics
  P(3,2,1)=p_go*0.2*adj(3,2);%toX1 % %World dynamics
  P(3,3,1)=p_stay;%self_loop % %World dynamics favor staying
  P(3,4,1)=p_go*0.2*adj(3,4);%toX3 % %World dynamics
  P(3,5,1)=p_go*0.1*double(adj(3,2)&&adj(3,3));%toX12 % %World dynamics
  P(3,6,1)=p_go*0.125*double(adj(3,2)&&adj(3,4));%toX13 % %World dynamics
  P(3,7,1)=p_go*0.125*double(adj(3,3)&&adj(3,4));%toX23 % %World dynamics
  P(3,8,1)=p_go*0.05*double(adj(3,2)&&adj(3,3)&&adj(2,4));%toX123 % %World dynamics
  P(3,1,1)=P(3,1,1)+(1-sum(P(3,:,1)));
  % stay from X3
  P(4,1,1)=p_go*0.2*adj(4,1);%toUO %World dynamics
  P(4,2,1)=p_go*0.2*adj(4,2);%toX1 % %World dynamics
  P(4,3,1)=p_go*0.2*adj(4,3);%toX2 % %World dynamics
  P(4,4,1)=p_stay;%self_loop % %World dynamics favor staying
  P(4,5,1)=p_go*0.1*double(adj(4,2)&&adj(4,3));%toX12 % %World dynamics
  P(4,6,1)=p_go*0.125*double(adj(4,2)&&adj(4,4));%toX13 % %World dynamics
  P(4,7,1)=p_go*0.125*double(adj(4,3)&&adj(4,4));%toX23 % %World dynamics
  P(4,8,1)=p_go*0.05*double(adj(4,2)&&adj(4,3)&&adj(4,4));%toX123 % %World dynamics
  P(4,1,1)=P(4,1,1)+(1-sum(P(4,:,1)));
  % stay from X12
  P(5,1,1)=p_go*0.05*double(adj(1,2)&&adj(1,3));%toUO %World dynamics
  P(5,2,1)=p_go*0.125*adj(2,3);%toX1 % %World dynamics
  P(5,3,1)=p_go*0.125*adj(3,2);%toX2 % %World dynamics
  P(5,4,1)=p_go*0.1*double(adj(4,2)&&adj(4,3));%toX3 % %World dynamics
  P(5,5,1)=p_stay;%self_loop % %World dynamics favor staying
  P(5,6,1)=p_go*0.25*adj(3,4);%toX13 % %World dynamics
  P(5,7,1)=p_go*0.1*adj(2,4);%toX23 % %World dynamics
  P(5,8,1)=p_go*0.25*double(adj(3,4)&&adj(2,4));%toX123 % %World dynamics
  P(5,1,1)=P(5,1,1)+(1-sum(P(5,:,1)));
  % stay from X13
  P(6,1,1)=p_go*0.05*double(adj(1,2)&&adj(1,4));%toUO %World dynamics
  P(6,2,1)=p_go*0.125*adj(2,4);%toX1 % %World dynamics
  P(6,3,1)=p_go*0.1*double(adj(3,2)&&adj(3,4));%toX2 % %World dynamics
  P(6,4,1)=p_go*0.125*adj(2,4);%toX3 % %World dynamics
  P(6,5,1)=p_go*0.25*adj(3,4);%toX12 % %World dynamics
  P(6,6,1)=p_stay;%self_loop % %World dynamics favor staying
  P(6,7,1)=p_go*0.1*adj(2,3);%toX23 % %World dynamics
  P(6,8,1)=p_go*0.25*double(adj(2,3)&&adj(3,4));%toX123 % %World dynamics
  P(6,1,1)=P(6,1,1)+(1-sum(P(6,:,1)));
  % stay from X23
  P(7,1,1)=p_go*0.05*double(adj(1,3)&&adj(1,4));%toUO %World dynamics
  P(7,2,1)=p_go*0.1*double(adj(2,3)&&adj(2,4));%toX1 % %World dynamics
  P(7,3,1)=p_go*0.125*adj(3,4);%toX2 % %World dynamics
  P(7,4,1)=p_go*0.125*adj(3,4);%toX3 % %World dynamics
  P(7,5,1)=p_go*0.2*adj(2,4);%toX12 % %World dynamics
  P(7,6,1)=p_go*0.2*adj(2,3);%toX13 % %World dynamics
  P(7,7,1)=p_stay;%self_loop % %World dynamics favor staying
  P(7,8,1)=p_go*0.2*double(adj(2,3)&&adj(2,4));%toX123 % %World dynamics
  P(7,1,1)=P(7,1,1)+(1-sum(P(7,:,1)));
  % stay from X123
  P(8,1,1)=p_go*0.025*double(adj(1,2)&&adj(1,3)&&adj(1,4));%toUO %World dynamics
  P(8,2,1)=p_go*0.1*double(adj(2,3)&&adj(2,4));%toX1 % %World dynamics
  P(8,3,1)=p_go*0.1*double(adj(2,3)&&adj(3,4));%toX2 % %World dynamics
  P(8,4,1)=p_go*0.1*double(adj(2,4)&&adj(3,4));%toX3 % %World dynamics
  P(8,5,1)=p_go*0.225*double(adj(2,4)&&adj(3,4));%toX12 % %World dynamics
  P(8,6,1)=p_go*0.225*double(adj(2,3)&&adj(3,4));%toX13 % %World dynamics
  P(8,7,1)=p_go*0.225*double(adj(2,3)&&adj(2,4));%toX23 % %World dynamics
  P(8,8,1)=p_stay;%self_loop % %World dynamics favor staying
  P(8,1,1)=P(8,1,1)+(1-sum(P(8,:,1)));

  P(g,:,1)=0.0;
  P(g,g,1)=1.0;

  % Definition of Transition matrix P(:,:,2) associated to action 2(go) and
  P(:,:,2)=zeros((m*n),(m*n));
  p_go=mm.p_go*1.4;
  if (p_go > 1.0)
      p_go=0.99;
  end
  p_stay=1-p_go;
  % GO
  % go from UO
  P(1,1,2)=p_stay;%self_loop % %World dynamics favor staying
  P(1,2,2)=p_go*0.2*adj(1,2);%toX1 % %World dynamics
  P(1,3,2)=p_go*0.2*adj(1,3);%toX2 % %World dynamics
  P(1,4,2)=p_go*0.2*adj(1,4);%toX3 % %World dynamics
  P(1,5,2)=p_go*0.125*double(adj(1,2)&&adj(1,3));%toX12 % %World dynamics
  P(1,6,2)=p_go*0.125*double(adj(1,2)&&adj(1,4));%toX13 % %World dynamics
  P(1,7,2)=p_go*0.1*double(adj(1,3)&&adj(1,4));%toX23 % %World dynamics
  P(1,8,2)=p_go*0.05*double(adj(1,2)&&adj(1,3)&&adj(1,4));%toX123 % %World dynamics
  P(1,1,2)=P(1,1,2)+(1-sum(P(1,:,2)));
  % go from X1
  P(2,1,2)=p_go*0.2*adj(2,1);%toUO %World dynamics
  P(2,2,2)=p_stay;%self_loop % %World dynamics favor staying
  P(2,3,2)=p_go*0.2*adj(2,3);%toX2 % %World dynamics
  P(2,4,2)=p_go*0.2*adj(2,4);%toX3 % %World dynamics
  P(2,5,2)=p_go*0.125*double(adj(2,2)&&adj(2,3));%toX12 % %World dynamics
  P(2,6,2)=p_go*0.1*double(adj(2,2)&&adj(2,4));%toX13 % %World dynamics
  P(2,7,2)=p_go*0.125*double(adj(2,3)&&adj(2,4));%toX23 % %World dynamics
  P(2,8,2)=p_go*0.05*double(adj(2,2)&&adj(2,3)&&adj(2,4));%toX123 % %World dynamics
  P(2,1,2)=P(2,1,2)+(1-sum(P(2,:,2)));
  % go from X2
  P(3,1,2)=p_go*0.2*adj(3,1);%toUO %World dynamics
  P(3,2,2)=p_go*0.2*adj(3,2);%toX1 % %World dynamics
  P(3,3,2)=p_stay;%self_loop % %World dynamics favor staying
  P(3,4,2)=p_go*0.2*adj(3,4);%toX3 % %World dynamics
  P(3,5,2)=p_go*0.1*double(adj(3,2)&&adj(3,3));%toX12 % %World dynamics
  P(3,6,2)=p_go*0.125*double(adj(3,2)&&adj(3,4));%toX13 % %World dynamics
  P(3,7,2)=p_go*0.125*double(adj(3,3)&&adj(3,4));%toX23 % %World dynamics
  P(3,8,2)=p_go*0.05*double(adj(3,2)&&adj(3,3)&&adj(2,4));%toX123 % %World dynamics
  P(3,1,2)=P(3,1,2)+(1-sum(P(3,:,2)));
  % gofrom X3
  P(4,1,2)=p_go*0.2*adj(4,1);%toUO %World dynamics
  P(4,2,2)=p_go*0.2*adj(4,2);%toX1 % %World dynamics
  P(4,3,2)=p_go*0.2*adj(4,3);%toX2 % %World dynamics
  P(4,4,2)=p_stay;%self_loop % %World dynamics favor staying
  P(4,5,2)=p_go*0.1*double(adj(4,2)&&adj(4,3));%toX12 % %World dynamics
  P(4,6,2)=p_go*0.125*double(adj(4,2)&&adj(4,4));%toX13 % %World dynamics
  P(4,7,2)=p_go*0.125*double(adj(4,3)&&adj(4,4));%toX23 % %World dynamics
  P(4,8,2)=p_go*0.05*double(adj(4,2)&&adj(4,3)&&adj(4,4));%toX123 % %World dynamics
  P(4,1,2)=P(4,1,2)+(1-sum(P(4,:,2)));
  % go from X12
  P(5,1,2)=p_go*0.05*double(adj(1,2)&&adj(1,3));%toUO %World dynamics
  P(5,2,2)=p_go*0.125*adj(2,3);%toX1 % %World dynamics
  P(5,3,2)=p_go*0.125*adj(3,2);%toX2 % %World dynamics
  P(5,4,2)=p_go*0.1*double(adj(4,2)&&adj(4,3));%toX3 % %World dynamics
  P(5,5,2)=p_stay;%self_loop % %World dynamics favor staying
  P(5,6,2)=p_go*0.25*adj(3,4);%toX13 % %World dynamics
  P(5,7,2)=p_go*0.1*adj(2,4);%toX23 % %World dynamics
  P(5,8,2)=p_go*0.25*double(adj(3,4)&&adj(2,4));%toX123 % %World dynamics
  P(5,1,2)=P(5,1,2)+(1-sum(P(5,:,2)));
  % go from X13
  P(6,1,2)=p_go*0.05*double(adj(1,2)&&adj(1,4));%toUO %World dynamics
  P(6,2,2)=p_go*0.125*adj(2,4);%toX1 % %World dynamics
  P(6,3,2)=p_go*0.1*double(adj(3,2)&&adj(3,4));%toX2 % %World dynamics
  P(6,4,2)=p_go*0.125*adj(2,4);%toX3 % %World dynamics
  P(6,5,2)=p_go*0.25*adj(3,4);%toX12 % %World dynamics
  P(6,6,2)=p_stay;%self_loop % %World dynamics favor staying
  P(6,7,2)=p_go*0.1*adj(2,3);%toX23 % %World dynamics
  P(6,8,2)=p_go*0.25*double(adj(2,3)&&adj(3,4));%toX123 % %World dynamics
  P(6,1,2)=P(6,1,2)+(1-sum(P(6,:,2)));
  % go from X23
  P(7,1,2)=p_go*0.05*double(adj(1,3)&&adj(1,4));%toUO %World dynamics
  P(7,2,2)=p_go*0.1*double(adj(2,3)&&adj(2,4));%toX1 % %World dynamics
  P(7,3,2)=p_go*0.125*adj(3,4);%toX2 % %World dynamics
  P(7,4,2)=p_go*0.125*adj(3,4);%toX3 % %World dynamics
  P(7,5,2)=p_go*0.2*adj(2,4);%toX12 % %World dynamics
  P(7,6,2)=p_go*0.2*adj(2,3);%toX13 % %World dynamics
  P(7,7,2)=p_stay;%self_loop % %World dynamics favor staying
  P(7,8,2)=p_go*0.2*double(adj(2,3)&&adj(2,4));%toX123 % %World dynamics
  P(7,1,2)=P(7,1,2)+(1-sum(P(7,:,2)));
  % go from X123
  P(8,1,2)=p_go*0.025*double(adj(1,2)&&adj(1,3)&&adj(1,4));%toUO %World dynamics
  P(8,2,2)=p_go*0.1*double(adj(2,3)&&adj(2,4));%toX1 % %World dynamics
  P(8,3,2)=p_go*0.1*double(adj(2,3)&&adj(3,4));%toX2 % %World dynamics
  P(8,4,2)=p_go*0.1*double(adj(2,4)&&adj(3,4));%toX3 % %World dynamics
  P(8,5,2)=p_go*0.225*double(adj(2,4)&&adj(3,4));%toX12 % %World dynamics
  P(8,6,2)=p_go*0.225*double(adj(2,3)&&adj(3,4));%toX13 % %World dynamics
  P(8,7,2)=p_go*0.225*double(adj(2,3)&&adj(2,4));%toX23 % %World dynamics
  P(8,8,2)=p_stay;%self_loop % %World dynamics favor staying
  P(8,1,2)=P(8,1,2)+(1-sum(P(8,:,2)));

  P(g,:,2)=0.0;
  P(g,g,2)=1.0;

  gen_reward=0.04; %What should be the general reward for all states
  R=zeros(m*n,action_no)+gen_reward;