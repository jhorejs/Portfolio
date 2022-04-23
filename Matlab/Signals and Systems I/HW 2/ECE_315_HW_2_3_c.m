clear; clc;
N = 50;
n = 0:1:N;
x = 4*exp(((-1/4)-(i*pi*n/25)));
P = sum(abs(x).^2)./(2*N)
subplot(2,1,1);
hold on
stem(n,real(x));
stem(n,imag(x));
grid on
title('x[n]');
xlabel('time(n)')
legend('Real','Imaginary');
hold off
subplot(2,1,2)
plot3(n,real(x),imag(x));
grid on 
xlabel('time');
title('R+I');