function [A, j] = Partition(A, p, r)
    x = A(r);
    i = p - 1;
    for j = p:r - 1
        if A(j) <= x
            i = i + 1;
            temp = A(i);
            A(i) = A(j);
            A(j) = temp;
        end
    end
    temp = A(i + 1);
    A(i + 1) = A(r);
    A(r) = temp;
    j = i + 1;
end
    