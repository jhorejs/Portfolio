clear all;
N = 9
x = -N:1:N;
y = -N:1:N;
a = 2*cos(pi*x/7-pi/4);
b = 2*cos(-13*pi*y/7-pi/4);
 
subplot(2,1,1)
stem(x,a);
title('x_1');
subplot(2,1,2)
stem(y,b);
title('x_2');
