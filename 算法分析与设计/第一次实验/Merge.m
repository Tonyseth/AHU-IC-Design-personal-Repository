function A=Merge(A,p,q,r)
    x=q-p+1;
    y=r-q;
    B=zeros(1,x+1);
    C=zeros(1,y+1);
    for i=1:x
        B(i)=A(p+i-1);
    end
    for j=1:y
        C(j)=A(q+j);
    end
    B(x+1)=inf;
    C(y+1)=inf;
    i=1;
    j=1;
    for k=p:r
        if B(i)<=C(j)
            A(k)=B(i);
            i=i+1;
        else
            A(k)=C(j);
            j=j+1;
        end
    end
end