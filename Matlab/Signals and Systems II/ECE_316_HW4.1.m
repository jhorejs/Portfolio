%% HW 4 deals with z transforms and simulink 
clc; clear all; 
syms z

n = [1 4 8];
d = [1 -.5 -7.5];
f = tf(n,d);
pzmap(f,z)
a = (z-(-2+2*1i))*(z-(-2-2*1i))/((z-3)*(z+2.5));
simplify(a)

%% Problem 2
clc; clear all; 
syms z
n = [1 4 8];
d = [1 -.5 -7.5];
f = tf(n,d)
[z p k] = residuez(n,d)
zplane(n,d)
hold on
plot(p,'^r')
hold off
iztrans((z.^2+4*z+8)/( z.^2 - 0.5*z - 7.5),z)

%%



%% Problem 5

H = tf([1 -2],[1 .5 0])
pzmap(H)
grid on

