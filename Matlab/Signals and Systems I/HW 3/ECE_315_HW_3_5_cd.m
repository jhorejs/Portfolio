close all; clear all; clc;
b = [-3/5, 1/2, 1];
a = [5/6, -2/3, 2];
% h = tf([-3/5, 1/2, 1],[5/6, -2/3, 2]);
% figure(1)
% bode(tf([-3/5, 1/2, 1],[5/6, -2/3, 2]),{0,15});
% grid on;

figure(2)
w = linespace(0,15);
h = freqs(b,a,w);


mag = abs(h);
phase = angle(h);
phasedeg = phase*180/pi;

subplot(2,1,1)
loglog(w,mag)
grid on
xlabel('Frequency (rad/s)')
ylabel('Magnitude')

subplot(2,1,2)
semilogx(w,phasedeg)
grid on
xlabel('Frequency (rad/s)')
ylabel('Phase (degrees)')