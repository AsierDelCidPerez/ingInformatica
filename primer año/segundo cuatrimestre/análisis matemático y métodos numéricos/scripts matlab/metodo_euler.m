
primera_solucion = 1;
paso = 0.01;
T = 3;

function [resultado] = funcion_diferencial(t, y) 
    resultado = log(t) * y^2;
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

hold on;
valores = euler_mod(primera_solucion, paso, T, @funcion_diferencial);
valores2 = euler(primera_solucion, paso, T, @funcion_diferencial);
x = 0:paso:T-paso;
plot(x, valores)
x = 0:paso:T-paso;
plot(x, valores2)



hold off