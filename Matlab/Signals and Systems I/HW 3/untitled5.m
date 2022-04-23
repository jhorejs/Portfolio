close all; 
clear all; 
clc;
b = [3 -1 2];
a = [1 2 2];
g = 0:.1:pi;
n = 3.*exp(g.*1i.*2)-exp(g.*1i)+2;
d = exp(g.*1i.*2)+2.*exp(g.*1i)+2;
H = n ./ d;
h = freqz(b,a,g);


subplot(4,1,1), stem(g, abs(H)), title('Amplitudexp plot');
subplot(4,1,2), stem(g, angle(H)), title('Phasexp plot');

subplot(4,1,3), stem(g, abs(h)), title('Amplitudexp plotted with freqs');
subplot(4,1,4), stem(g, angle(h)), title('Phasexp plot with freqs');