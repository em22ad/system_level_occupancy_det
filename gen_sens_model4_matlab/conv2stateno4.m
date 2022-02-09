function [state,g_label]=conv2stateno4(obs)
state=1;
g_label={'Unocc'};    
if isequal(obs,[0 0 0 0]) % UO
    state=1;
    g_label={'Unocc'};
elseif isequal(obs,[1 0 0 0]) % X1
    state=2;
    g_label={'X_1'};
elseif isequal(obs,[0 1 0 0]) % X2
    state=3;
    g_label={'X_2'};
elseif isequal(obs,[0 0 1 0]) % X3
    state=4;
    g_label={'X_3'};
elseif isequal(obs,[0 0 0 1]) % X4
    state=5;
    g_label={'X_4'};
elseif isequal(obs,[1 1 0 0]) % X12
    state=6;
    g_label={'X_1,X_2'};
elseif isequal(obs,[1 0 1 0]) % X13
    state=7;
    g_label={'X_1,X_3'};
elseif isequal(obs,[1 0 0 1]) % X14
    state=8;
    g_label={'X_1,X_4'};
elseif isequal(obs,[0 1 1 0]) % X23
    state=9;
    g_label={'X_2,X_3'};
elseif isequal(obs,[0 1 0 1]) % X24
    state=10;
    g_label={'X_2,X_4'};
elseif isequal(obs,[0 0 1 1]) % X34
    state=11;
    g_label={'X_3,X_4'};
elseif isequal(obs,[1 1 1 0]) % X123
    state=12;
    g_label={'X_1,X_2,X_3'};
elseif isequal(obs,[1 1 0 1]) % X124
    state=13;
    g_label={'X_1,X_2,X_4'};
elseif isequal(obs,[1 0 1 1]) % X134
    state=14;
    g_label={'X_1,X_3,X_4'};
elseif isequal(obs,[0 1 1 1]) % X234
    state=15;
    g_label={'X_2,X_3,X_4'};
elseif isequal(obs,[1 1 1 1]) % X1234
    state=16;
    g_label={'X_1,X_2,X_3,X_4'};
end
