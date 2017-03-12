//Declara la matriz cuadraada de coeficientes como A
//Declara el vector columna de constantes o términos independientes como B

//Calcula el determinante (D)
D = det(A)
[r c] = size(A)
for i=1:1:r //Ciclo para encontrar tantas incógnitas como ecuaciones haya
    Di = A
    //Sustituye la columna de la incógnita, con la de términos independientes
    Di(:,i)=B
    //Calcula el valor de la incógnita por regla de Cramer
    X(i) = det(Di)/D
end

//Despliega el vector de valores de las incógnitas
disp(X)
