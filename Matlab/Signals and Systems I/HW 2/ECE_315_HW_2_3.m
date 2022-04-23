clear all;
x = -2.*pi:2.*pi:2.*pi;
y = linspace(pi/4,13/4*pi,50)';
z = linspace(pi/4,13/4*pi,50)';


a = 2*cos(pi*y/7-pi/4);
b = 2*sin(3*pi*z/10+pi/2);



% hold on
% stem(y,a);
 stem(z,b);
% plot(x,a);
% plot(x,b);
% hold off