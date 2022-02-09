function show_map (map,R)
  % LEFT = 1
  m=size(map,1);
  fprintf('\nPolicy map:\n');
  for i = 1:m
      if (R(i,1) == -999.0)
        fprintf('x  ');
      elseif (map(i,1) == 1)
        fprintf('s  ');
      elseif (map(i,1) == 2)
        fprintf('g  ');
      end
  end
  fprintf('\n');
  disp('x:obstacle')
  %  1  4  7
  %  2  5  8
  %  3  6  9
  
  % 1 5  9   13
  % 2 6  10  14
  % 3 7  11  15
  % 4 8  12  16
  
  % 1 6  11 16
  % 2 7  12 17 
  % 3 8  13 18
  % 4 9  14 19
  % 5 10 15 20