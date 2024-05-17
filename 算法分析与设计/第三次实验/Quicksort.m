function A = Quicksort(A, p, q)
    if p < q
        [A, r] = Partition(A, p, q);
        A = Quicksort(A, p, r - 1);
        A = Quicksort(A, r + 1, q);
    end
end
