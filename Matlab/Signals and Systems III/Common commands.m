%% Magnitude and Phase
clc; clear all; 
s = tf('s')
n = 2500;
d = s*(s+5)*(s+50);
g = n/d; %<--------fill in the 
figure(1)
margin(g)
%% Roots
clc; clear all;
syms s
a = [1 4 8 4];
r = roots(a)
b = s^3+4*s^2+8*s+4;
c = root(b,s)

%% Bode
clc; clear all; 


%% Simplify polynomeal
clc; clear all; 
syms s x
a = (-1/(s+2))*(s/(s^2+9));
simplify(a)
expand(a)
factor(a)
b = factor(s^(3)+2*s^2+3*(1+x)*s+6);
b
c = factor((1 - s^2)*(1 - s));
c

%% Laplace and Inverse Laplace
clc; clear all; 
syms s t
a = (s)/((s+2)^2+16)
F = laplace(a,t,s)
f = ilaplace(F,s,t)


%% residue
clc; clear all;

n = [1];
d = [1 1 4];
n1= [1 0];
d1= [1 10];
t = tf(n,d)
t1= tf(n1,d1)
a = t/(1+t*t1);

[r,p,k] = residue(a)



%% TIME CONSTANT   SETTLING TIME
clc; clear all; 
s = tf('s');
k = 1; 
G = 1/s * 5/(s+5)
[z,p,k] = zpkdata(G)
G1 = zpk(z,p,k,'DisplayFormat', 'timeconstant')
damp(G)
[w, zeta, p] = damp(G)
tau = 1./w 


%%
clc; clear all; 
syms s
t = linspace(0,1,5)
G = 1/s * 5/(s+5);
a = ilaplace(G);
figure()
plot(t,a)
