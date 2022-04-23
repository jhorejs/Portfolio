clc
clear 
close all

% SEE ALCAN TABLE AT 50C°---------------
r  = .0481;     % r(Ohms/1000ft)
xL = .0835;     % XL(Ohms/1000ft)
xC = .539e+06;  % XC(Mohms*1000ft)
GMR = .0265;    % 
% --------------------------------------
d = 95;         % mi
yC = 1i*1/xC;   %
dAB = 8;        % line distance in ft
dBC = 8;        % line distance in ft
dAC = 8;        % line distance in ft
GMD = nthroot(dAB*dBC*dAC,3);
R = r*(d*5.28);                  % AC resistance
XL = (xL*(d*5.28))*log(GMD/GMR); % Inductive reactance
XC = (xC/(d*5.28))*log(GMD/GMR); % Total capacitive reactance
YC = 1i*1/XC;                    % Total capacitive admittance
z = (r+1i*xL)*(d*5.28);          % ABCD calculations
y = yC*(d*5.28);
A = 1 + (z*y)/2;
B = z;
C = (z*y)/4 + 1;
D = A;

Pr = 'The following is per phase ';
disp(Pr);
Resistance  = ['1.  AC Resistance:    R = ', num2str(R,'%.3f'),' ',char(937) ];
Inductance1 = ['2.    L Reactance:  X_L = ', num2str(XL,'%.3f'),' ',char(937)];
Inductance2 = ['      C Reactance:  X_C = ', num2str(XC,'%.3f'),' ',char(937)];
Capacitive  = ['3.   C Admittance:  Y_C = ', num2str(YC,'%.3f'),' ',char(937),'^-1'];
disp(Resistance);
disp(Inductance1);
%disp(Inductance2);
disp(Capacitive);
Co = '4. The following are the coefficients ';
disp(Co);
PA= ['                      A = ', num2str(A,'%.3f')];
PB= ['                      B = ', num2str(B,'%.3f')];
PC= ['                      C = ', num2str(C,'%.3f')];
PD= ['                      D = ', num2str(D,'%.3f')];
disp(PA);
disp(PB);
disp(PC);
disp(PD);
