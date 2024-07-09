function [tree, weight] = Kruskal(nodes, edges)
% Kruskals算法求最小生成树
% nodes: 节点数
% edges: 边集，每行三列，分别是边的两个节点和权值
% tree: 最小生成树的边集
% weight: 最小生成树的权值
    edges = sortrows(edges, 3); % 按权值排序
    tree = zeros(size(edges)); % 最小生成树的边集
    treeCount = 0;% 最小生成树的边数
    sets = num2cell(1:nodes);% 节点集合
    weight = 0;% 最小生成树的权值
    for i = 1:size(edges, 1)% 遍历边集
        n1 = edges(i, 1);% 边的一个节点
        n2 = edges(i, 2);% 边的另一个节点
        s1 = find(cellfun(@(s) ismember(n1, s), sets));% 查找节点所在集合
        s2 = find(cellfun(@(s) ismember(n2, s), sets));% 查找节点所在集合
    % 算法的关键
    %在sets这个元胞数组中使用cellfun和ismember函数查找节点n1和n2所在的集合s1和s2
    %cellfun对sets中的每个元素应用了一个匿名函数@(s) ismember(n1/n2, s)，这个匿名函数 @(s) ismember(n1, s) 接受一个参数 s，并检查 n1 是否是 s 的一个元素。ismember 函数返回一个逻辑值，如果 n1 是 s 的一个元素，那么返回 true，否则返回 false。因此，cellfun(@(s) ismember(n1, s), sets) 返回一个逻辑数组，其中的每个元素表示 n1 是否是 sets 中对应元素的一个成员。最后，find 函数被用来找到所有 true 的元素的索引。所以，s1 是一个包含了所有包含 n1 的 sets 元素的索引的数组。
        if s1 ~= s2
            treeCount = treeCount + 1;
            tree(treeCount, :) = edges(i, :);
            weight = weight + edges(i, 3);
            sets{s1} = union(sets{s1}, sets{s2});
            sets(s2) = [];
        end

    end
    tree = tree(1:treeCount, :);
end
