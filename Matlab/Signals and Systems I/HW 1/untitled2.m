clear; clc; 
a = 3/2;
t = -100:.0001:100;
x = asin(sin(pi.*t+a.*pi))+a+16/25.*asin(sin(16/25.*pi.*t-pi/2))+1;

plot(t,x)
grid on

