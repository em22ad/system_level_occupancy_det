function [times,tim,Po,lobs]=read_last_iter4(path)
fileID = fopen(path,'r');
snapshot = fscanf(fileID,'%f');
times=snapshot(1);
tim=snapshot(2);
n=4;
lobs=zeros(1,n);
for i=1:n
    %3:6
    lobs(i)=snapshot(i+2);
end
Po=zeros(1,2^n);
for i=1:2^n
    %7:22
    Po(i)=snapshot(i+2+n);
end
fclose(fileID);