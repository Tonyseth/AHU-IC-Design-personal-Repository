function C = Store(L, V, D)
    n = length(L);
    C = zeros(n, D);
    for y = 1:D
        if y >= L(1)
            C(1, y) = V(1);
        end
    end
    for k = 2:n
        for y = 1:D
            C(k, y) = C(k-1, y);
            if y >= L(k) && (y-L(k)) > 0 && C(k-1, y-L(k)) + V(k) > C(k-1, y)
                C(k, y) = C(k-1, y-L(k)) + V(k);
            end
        end
    end
end
