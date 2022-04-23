% % n
%Program to compute the signal energy or power of some example signals

n = 0:100;
x = abs(2*sin(3*n/10+pi/2)).^2; 
xsq = x.^2;
Ex = sum(xsq)/100;
disp(['(b) Ex = ',num2str(Ex)]);

stem(x)
% N0 = 35;
% n = 0:N0-1;
% x = 4*impND(5,n) - 7*impND(7,n) ; 
% xsq = x.^2 ;
% Px = sum(xsq)/N0;
% disp(['(d) Px = ',num2str(Px)]);