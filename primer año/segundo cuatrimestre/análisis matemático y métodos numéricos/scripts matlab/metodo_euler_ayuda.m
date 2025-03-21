
primera_solucion = 1;
paso = 0.1;
T = 100

function [resultado] = funcion_diferencial(t, y)
    resultado =  y^2;
end

function [resultado] = solucion(t)
    resultado = (1)/(1-t);
end

function [resultado_discretizado] = euler(primera_solucion, paso, T, funcion_diferencial)
    valores = zeros(T/paso);
    valores(1) = primera_solucion;
    for i = (1: T/paso -1)
        valores(i+1) = valores(i) + paso * funcion_diferencial(paso*i, valores(i));
    end
    resultado_discretizado = valores;
end

function [res] = euler_mod(primera_solucion, paso, T, funcion_diferencial)
    valores = zeros(T/paso);
    valores_aux = zeros(T/paso);
    valores_aux(1)=primera_solucion;
    valores(1) = primera_solucion;
    for i = 1:T/paso-1
        valores_aux(i+1) = valores_aux(i) + (paso/2)*funcion_diferencial(paso*i, valores_aux(i));
        valores(i+1) = valores(i) + paso*funcion_diferencial(paso*i + paso/2, valores_aux(i+1));
    end

    res = valores;

end


y = zeros(T/paso);
v = zeros(T/paso);
y(1) = 1;
v(1) = 0;

# Euler vectores
for i = 1:T/paso -1
  y(i+1) = y(i)  + paso * v(i);
  v(i+1) = v(i) + paso*(-1*y(i));
end

y = zeros(T/paso-1);

y(1) = 1;
v(1) = 0;

# Euler modificado
for t=1:T/paso-1
  aux1 = y(t) + (paso/2) * v(t);
  aux2 = v(t) + (paso/2) * (-y(t));

 y(t+1) = y(t)  + (paso)* aux2; # Euler mod para el primero
  v(t+1) = v(t) + paso*(-aux1);
end

plot(y);

