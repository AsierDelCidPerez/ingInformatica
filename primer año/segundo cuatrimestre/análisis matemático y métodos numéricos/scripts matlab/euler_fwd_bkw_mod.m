
% Parameters of Euler
t0 = 0;
y0 = 1;
T = 100;
h = 0.1;

function [res] = euler(T, h, funcion, y0)
    y = zeros(T/h-1);
    y(1) = y0;
    for i=1:length(y)
        y(i+1) = y(i) + h*funcion(h*i, y(i));
    end
    res = y;
end

% This function solves a second-order differential equation of the form
% y'' = f(t, y(t)) and y'(t0)=y0 and y(t1)=y1 by using the euler fwd method
% Locally, the method descomposes the differential equation in two smaller
% differential equations using the variable change: v = y'. Following this:
% [y_i+1]   [y_i]     [    v_i   ]
% [v_i+1] = [y_i] + h [f(t, y(t))]
% T is the range [0, T] of discretization of the function. 
function y = euler_vectorial(T, h, funcion, y0, v0)
    y = zeros(T/h-1);
    v = zeros(T/h-1);
    y(1) = y0;
    v(1) = v0;
    for i = 1:length(y)
        y(i+1) = y(i) + h * v(i);
        v(i+1) = v(i) + h* funcion(h*i, y(i));
    end
end

% Euler modified is a numerical method based on euler method. 
%
function [y] = euler_mod (T, h, funcion, y0)
    y = zeros(T/h-1);
    y(1) = y0;
    for i = 1:length(y)
        aux = y(i) + (h/2) * funcion(i*h, y(i));
        y(i+1) = y(i) + (h) * funcion(i*h + h/2, aux);
    end
end

function [y] = euler_modificado_vectorial (T, h, funcion, y0, v0)
    y = zeros(T/h-1);
    v = zeros(T/h-1);
    y(1) = y0;
    v(1) = v0;
    for i = 1:length(y)
        aux = y(i) + (h/2) * v(i);
        aux2 = v(i) + (h/2) * funcion(i*h + h/2, y(i));
        v(i+1) = v(i) + h * funcion(i*h + h/2, aux);
        y(i+1) = y(i) + h *aux2;
    end
end

function [res] = miFuncion(t, y)
    res = -y;
end

y = euler_modificado_vectorial(T, h, @miFuncion, 0, 1);
x = 0:h:T-2*h;
plot(x, y)