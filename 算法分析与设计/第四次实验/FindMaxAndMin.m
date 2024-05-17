function [max, min] = FindMaxAndMin(L)
    n = length(L);
    if n == 1
        max = L(1);
        min = L(1);
        return;
    end
    [max, max_idx] = FindMax(L);
    L(max_idx) = [];
    [min, ~] = FindMin(L);
end