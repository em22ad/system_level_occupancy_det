function sens_model=read_model(path,m,n)
sens_model=ones(m,n);
fileID = fopen(path,'r');
data = fscanf(fileID,'%f');
ctr=1;
for i=1:m
    for j=1:n
        sens_model(i,j)=data(ctr);
        ctr=ctr+1;
    end
end
fclose(fileID);