clc
clear 
close all

% Enter; r(Ohms/1000ft), xL(Ohms/1000ft), xC(Mohms*1000ft), GMR(ft) and length of line in mi.
% For type of line to be tested from ALCAN table, Top = 50C

r = .0481;
xL = .0835;
xC = .539e+06;
GMR = .0265;
d = 95; %miles
yC = 1i*1/xC;

% Calculate Geometric Mean Distance GMD
dAB = 8; 
dBC = 8;
dAC = 8;
GMD = nthroot(dAB*dBC*dAC,3);

% Total AC resistance
R = r*(d*5.28);

% Total inductive reactance
XL = (xL*(d*5.28))*log(GMD/GMR);

% Total capacitive reactance
XC = (xC/(d*5.28))*log(GMD/GMR);

% Total capacitive admittance
YC = 1i*1/XC;

% ABCD calculations
z = (r+1i*xL)*(d*5.28);
y = yC*(d*5.28);

A = 1 + (z*y)/2;
B = z;
C = (z*y)/4 + 1;
D = A;

response1 = ['R_total= ', num2str(R), ' \\pi ' ' X_L_total = ', num2str(XL), ' \? ' 'Total Capacitive Admittance = ', num2str(YC), ' Siemens. '];
disp(response1);
response2 = ['A = ', num2str(A), ' B = ', num2str(B), ' C = ', num2str(C), ' D = ', num2str(D),];
disp(response2);
