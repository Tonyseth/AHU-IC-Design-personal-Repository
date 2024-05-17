function [max, min]= FindMaxMin(L)
    n = length(L);
    if n == 1
        max = L(1);
        min = L(1);
    else
        [max1, min1] = FindMaxMin(L(1:2:n));
        [max2, min2] = FindMaxMin(L(2:2:n));
        max = max1;
        min = min1;
        if max2 > max
            max = max2;
        end
        if min2 < min
            min = min2;
        end
    end
end