function [tree, weight] = Kruskal(nodes, edges)
% Kruskals�㷨����С������
% nodes: �ڵ���
% edges: �߼���ÿ�����У��ֱ��Ǳߵ������ڵ��Ȩֵ
% tree: ��С�������ı߼�
% weight: ��С��������Ȩֵ
    edges = sortrows(edges, 3); % ��Ȩֵ����
    tree = zeros(size(edges)); % ��С�������ı߼�
    treeCount = 0;% ��С�������ı���
    sets = num2cell(1:nodes);% �ڵ㼯��
    weight = 0;% ��С��������Ȩֵ
    for i = 1:size(edges, 1)% �����߼�
        n1 = edges(i, 1);% �ߵ�һ���ڵ�
        n2 = edges(i, 2);% �ߵ���һ���ڵ�
        s1 = find(cellfun(@(s) ismember(n1, s), sets));% ���ҽڵ����ڼ���
        s2 = find(cellfun(@(s) ismember(n2, s), sets));% ���ҽڵ����ڼ���
    % �㷨�Ĺؼ�
    %��sets���Ԫ��������ʹ��cellfun��ismember�������ҽڵ�n1��n2���ڵļ���s1��s2
    %cellfun��sets�е�ÿ��Ԫ��Ӧ����һ����������@(s) ismember(n1/n2, s)������������� @(s) ismember(n1, s) ����һ������ s������� n1 �Ƿ��� s ��һ��Ԫ�ء�ismember ��������һ���߼�ֵ����� n1 �� s ��һ��Ԫ�أ���ô���� true�����򷵻� false����ˣ�cellfun(@(s) ismember(n1, s), sets) ����һ���߼����飬���е�ÿ��Ԫ�ر�ʾ n1 �Ƿ��� sets �ж�ӦԪ�ص�һ����Ա�����find �����������ҵ����� true ��Ԫ�ص����������ԣ�s1 ��һ�����������а��� n1 �� sets Ԫ�ص����������顣
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
