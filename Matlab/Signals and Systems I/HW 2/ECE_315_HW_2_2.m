clear all
syms n m k ;
x = -0:1:21;

a = piecewise(0 <= n <=20, (20.*n-n.^2), 0);                              %Part a
A = piecewise(0 <= n <=20, (20.*n-n.^2)-(20.*(n-1)-(n-1).^2), 0);       %Part b
b = piecewise(0 <= m <=20, (1+20.*m-m.^2), 1);                          %Part a
B = piecewise(0 <= m <=20, (1+20.*m-m.^2)-(1+20.*(m-1)-(m-1).^2), 1);    %Part b
c = piecewise(0 <= m <=20, (1+20.*m-m.^2), 0);                          %Part a
C = piecewise(0 <= m <=20, (1+20.*m-m.^2)-(1+20.*(m-1)-(m-1).^2), 0);    %Part b
x1 = subs(a, n, x);
X1 = subs(A, n, x);
x2 = subs(b, m, x);
X2 = subs(B, m, x);
x3 = subs(c, m, x);
X3 = subs(C, m, x); 
%Part (a)-------------------------------------------
% figure(1)
% hold on
% stem(x1);
% stem(x2);
% title('comparing x2 and x3');
% hold off
%Part (b)-------------------------------------------
% figure(1)
% hold on
% stem(X2);
% stem(X3);
% title('comparing x2 and x3');
% hold off;
%Part (c)-------------------------------------------
% cumsum(X2)
% figure(1)
% stem(cumsum(X2));