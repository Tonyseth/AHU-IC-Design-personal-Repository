function [max, k] = FindMax(L)
    max = L(1);
    k = 1;
    for i = 2:length(L)
        if max < L(i)
            max = L(i);
            k = i;
        end
    end
end
