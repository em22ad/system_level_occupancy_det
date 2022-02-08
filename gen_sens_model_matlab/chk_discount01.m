function [ok] = chk_discount01(discount)
ok =1;
for a=1:size(discount,2) % run through all actions
    disc=discount(:,a);
    if ((size(find(disc<=0),1) > 0) || (size(find(disc>=1),1) > 0))
        ok = 0;
        break
    else
        ok = 1;
    end 
end