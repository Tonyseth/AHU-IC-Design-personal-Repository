function A=Mergesort(A,p,r)
    if p<r
        q=floor((p+r)/2);
        A=Mergesort(A,p,q);
        A=Mergesort(A,q+1,r);
        A=Merge(A,p,q,r);
    end
end
