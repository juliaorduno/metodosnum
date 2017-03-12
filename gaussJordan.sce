X = [A B]
[rX cX] = size(X)

for p=1:1:rX-1
    pivote = X(p,p);
    for i=p+1:1:rX
        prim_fila = X(i,p)
        X(i,:) = X(i,:)-(X(p,:)/pivote)*prim_fila
    end;
end

for p=rX:-1:2
    pivote = X(p,p);
    for i=p-1:-1:1
        prim_fila = X(i,p)
        X(i,:) = X(i,:)-(X(p,:)/pivote)*prim_fila
    end;
end

for i=1:rX
    x = X(i,i)
    X(i,:) = X(i,:)/x
end
