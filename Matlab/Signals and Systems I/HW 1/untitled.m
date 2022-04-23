H = 1.5;
T = 2*pi*1/2;
t = -10:10;
x1 = H*sawtooth(T*t,1/2)+H;
subplot(3,1,1)
plot(t,x1)
title('Combined Plots');
grid on
 
x2 = H*sawtooth(T*((t/2)+1),1/2)+H;
subplot(3,1,2)
plot(t,x2)
title('Part b(proper order)');
grid on
 
x4 = H*sawtooth(T*(t+1)/2,1/2)+H;
subplot(3,1,3)
plot(t,x4)
title('Part d');
grid on

