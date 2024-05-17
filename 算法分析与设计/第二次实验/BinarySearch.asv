function index = BinarySearch(T, l, r, x)
    while l <= r
        m = floor((l + r) / 2);
        if T(m) == x
            index = m;
            return;
        elseif T(m) < x
            l = m + 1;
        else
            r = m - 1;
        end
    end
    index = -1;
end
