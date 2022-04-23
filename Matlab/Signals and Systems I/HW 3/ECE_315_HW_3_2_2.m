clc
close all
clear all

syms n; 
n = -1:.1:10;
a = 1/2+i/2;
b = 1/2-i/2;
c = i-1;
d = -1-i;

h = 3.*(a.*c.^(n)+b.*d.^(n)).*heaviside(n)-(a.*c.^(n-1)+b.*d.^(n-1)).*heaviside(n-1)+2.*(a.*c.^(n-2)+b.*d.^(n-2)).*heaviside(n-2)
stem3(n,real(h),imag(h));
xlabel('time');
ylabel('real');
zlabel('imaginary');
grid on