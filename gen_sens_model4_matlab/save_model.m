function save_model(path,sens_model)
fileID = fopen(path,'w');
rows = size(sens_model,1);
cols = size(sens_model,2);
for i = 1:rows
    for j = 1:cols
        fprintf(fileID,'%4.4f ',sens_model(i,j));
    end
    fprintf(fileID,'\n');
end
fclose(fileID);