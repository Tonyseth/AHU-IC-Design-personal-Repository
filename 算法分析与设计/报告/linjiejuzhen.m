clc; clear; close all;
% 邻接矩阵聚类
n = 12;
[x, y] = ginput(n);
plot(x, y, 'r*')
hold on
% 计算邻接矩阵
A = zeros(n);
for i = 1:n
    for j = i:n
        A(i, j) = sqrt((x(i) - x(j)) ^ 2 + (y(i) - y(j)) ^ 2);
        A(j, i) = A(i, j); % 确保矩阵是对称的
    end
end
% 计算特征值和特征向量
[U, V] = eig(A);
V = diag(V); % 提取对角线元素
% 计算特征值间隔
Gap = abs(diff(V) ./ V(2:end));
% 自动选择最佳聚类数
[~, best_k] = max(Gap);
best_k = best_k + 1; % 因为Gap的长度比n小1
% 使用K-means进行聚类
Y = U(:, 1:best_k);
[idx, ~] = kmeans(Y, best_k);
% 绘制聚类结果
colors = hsv(best_k);
for i = 1:best_k
    cluster = idx == i;
    scatter(x(cluster), y(cluster), 50, colors(i,:), 'filled')
end
title(sprintf('最佳聚类数: %d', best_k))
legend('原始数据点', 'Location', 'bestoutside')
hold off
% 显示Gap值
figure;
bar(Gap);
title('特征值间隔');
xlabel('间隔索引');
ylabel('间隔值');