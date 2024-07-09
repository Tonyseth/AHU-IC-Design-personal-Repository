% 定义图的节点和边
nodes =10;
edges = [7 8 1; 1 2 2; 1 3 3; 4 6 3; 2 3 5; 5 6 4;4 5 5;2 7 8; 3 8 8; 2 4 18];
% 调用 Kruskal 函数
[tree, weight] = Kruskal(nodes, edges);
% 绘制输入的图
G = graph(edges(:,1), edges(:,2), edges(:,3));
figure;
subplot(1,2,1);
plot(G, 'EdgeLabel',G.Edges.Weight);
title('Input Graph');
% 绘制生成的最小生成树
T = graph(tree(:, 1), tree(:, 2), tree(:, 3));
subplot(1, 2, 2);
p = plot(T, 'EdgeLabel', T.Edges.Weight);
title('Minimum Spanning Tree');
p.NodeColor = 'r';
p.EdgeColor = 'k';
p.MarkerSize = 10;
p.LineWidth = 2;
p.NodeLabel = cellstr(num2str((1:T.numnodes)'));
