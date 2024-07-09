L = [1, 3, 4, 5]; % 货柜长度
V = [1, 4, 5, 7]; % 货柜值
D = 7;            % 库房长度
C = Store(L, V, D);
disp('最大的收益矩阵C:');
disp(C);
disp('最大的收益:');
disp(C(end, end));
