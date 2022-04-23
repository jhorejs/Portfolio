clear all; close all; clc;
t = -1:.1:3;
x = zeros(1,length(t));
h = zeros(1,length(t));
for i=1:numel(t)
    if t(i)<0 || t(i)>2
        x(i)=0;
    else
        x(i) = 2.*(t(i))-(t(i)).^2;
    end
    if t(i)<=1 || t(i)>2
        h(i) = 0;
    else
        h(i) = 2-t(i);
    end
end
y = conv(x,h,'same');

plot(t,h,'r',t,x,'b',t,y,'g')
xlabel('time(t)')
ylabel('amplitude')
title('convolution integral')


