close all;
clear all;
clc;
syms t;%t = -1:.1:3;
x = piecewise(1<t && t<2,2-t);
h = piecewise(0<t && t<2,2.*t-t.^2);
y = conv(x,h);