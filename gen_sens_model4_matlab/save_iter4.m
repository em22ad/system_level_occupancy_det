function save_iter4(path,tim,lobs,Po,times)
n=4;
x=zeros(2+n+(2^n),1);
x(1) = times;
x(2) = tim;

for i=1:n
    x(i+2)= lobs(i);
end

for i=1:2^n
    x(i+2+n)= Po(i);
end

fileID = fopen(path,'w');
n = length(x);
for i = 1:n
        fprintf(fileID,'%4.4f\n',x(i));
end
fclose(fileID);