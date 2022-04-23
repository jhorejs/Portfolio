clc; 
clear all; 
close all; 

syms a b c x;
a = 1;
b = -2;
c = 2;
eqn = a*x^2 + b*x + c == 0;

S = solve(eqn,x)


