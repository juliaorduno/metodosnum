X = [A B]
[rX cX] = size(X)

//Eliminación hacia adelante
for p=1:1:rX-1
    pivote = X(p,p);
    for i=p+1:1:rX
        prim_fila = X(i,p)
        X(i,:) = X(i,:)-(X(p,:)/pivote)*prim_fila
    end;
end

//Sustitución hacia adelante
x=[]
x(rX) = X(rX,cX)/X(rX,cX-1);
for i=rX-1:-1:1
    sumk = 0
    for k=i+1:rX
        sumk = sumk+X(i,k)*x(k);
    end;
    x(i)=(X(i,cX)-sumk)/X(i,i);
end;
