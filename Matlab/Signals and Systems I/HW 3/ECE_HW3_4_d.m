close all;
clear all;
clc;
syms t
h = piecewise(t<1,0,1<=t<2, 2-t, t>2,0);
x = piecewise(t<0,0,0<=t<2, 2*t-t^2, t>2,0);
figure(1)
fplot(h);
hold on
fplot(x);
grid on
hold off