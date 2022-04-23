clear all;
N = 14;
t = pi/4:.1:N+pi/4;
n = pi/4:.1:N+pi/4;
x = 2*cos(pi*n/7-pi/4);
a = 2*cos(-13*pi*t/7-pi/4);
P = sum(abs(x).^2)./(2*N);
figure(1)
hold on
stem(n,x);
plot(t,a);
grid on
xlabel('time(n)')
legend('Real','Imaginary');
hold off



