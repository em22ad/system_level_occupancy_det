function [obs]=conv2stateobs4(sest)
obs=[0 0 0 0];   
if (sest == 1) % UO
    obs=[0 0 0 0];
elseif (sest == 2) % X1
    obs=[1 0 0 0];
elseif (sest == 3) % X2
    obs=[0 1 0 0];
elseif (sest == 4) % X3
    obs=[0 0 1 0];
elseif (sest == 5) % X4
    obs=[0 0 0 1];
elseif (sest == 6) % X12
    obs=[1 1 0 0];
elseif (sest == 7) % X13
    obs=[1 0 1 0];
elseif (sest == 8) % X14
    obs=[1 0 0 1];
elseif (sest == 9) % X23
    obs=[0 1 1 0];
elseif (sest == 10) % X24
    obs=[0 1 0 1];
elseif (sest == 11) % X34
    obs=[0 0 1 1];
elseif (sest == 12) % X123
    obs=[1 1 1 0];
elseif (sest == 13) % X124
    obs=[1 1 0 1];
elseif (sest == 14) % X134
    obs=[1 0 1 1];
elseif (sest == 15) % X234
    obs=[0 1 1 1];
elseif (sest == 16) % X1234
    obs=[1 1 1 1];
end
