clc;
clear all;
close all; 

%n = %-6:1:6; 
x = [0 1 -1 2 -2 1 -1 0];
h = [0 0 0 3 2 1 0 0];
y = conv(x,h)
subplot(131);
stem(x);
title('x[n]');
subplot(132);
stem(h);
title('h[n]');
subplot(133)
stem(y);
title('y[n]');


