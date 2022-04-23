clc; 
close all;
k = 0:1:20;
a = exp(-2.*1i.*pi.*k);
b = 1i./(pi.^(3).*k.^(3)).*(-2.*pi.^(5).*k.^(5)+2.*1i.*pi.*k.*a+a-1);
x = piecewise(k = 0, 8/3,k>0,b);

bode(x);