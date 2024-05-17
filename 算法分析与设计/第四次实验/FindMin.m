function [min, k] = FindMin(L)
    min = L(1);
    k = 1;
    for i = 2:length(L)
        if min > L(i)
            min = L(i);
            k = i;
        end
    end
end
