function C = FindIntersection(A, B)
    % 初始化哈希表H
    H = dictionary('KeyType', 'int32', 'ValueType', 'int32');

    % 遍历集合B，将每个元素添加到哈希表H中
    for i = 1:length(B)
        H(B(i)) = 1;
    end

    % 初始化交集集合C为空
    C = [];

    % 遍历集合A中的每个元素
    for i = 1:length(A)
        % 如果当前元素在哈希表H中
        if isKey(H, A(i))
            % 将元素添加到集合C中
            C = [C, A(i)];
        end
    end
end
