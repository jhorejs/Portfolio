clc; clear all; close all;

%------------------- Part 1------------------
VA  = 112;
B   = 50;
VBE = 0.7;
A   = 4700;
C   = 5;

RC  = A;
RE  = A;
REE = A;
VCC = C;
VEE = C;

IEE = VEE/(2*REE);
IC  = (VEE-VBE)/(2*RE);
IB  = IC/B;
aF  = 2*IC/IEE;
VC  = VCC - IC*RC;
VE  = IEE/(2*RE);
VCE = VC+VBE-IC*RC;
gm  = IC*40;
rpi = B/gm;
ro  = (VA +VCE)/IC;
Add = gm*(RC);
Acc = abs(RC*(1/(B*ro) - 1/(2*REE)));
Rid = 2*rpi;
Ric = (rpi+(B+1)*2*REE)/2;
Rod = 2*(RC*ro)/(RC+ro);
CMRR= gm*REE;

    fprintf('RC  = %3.2f k\nRE  = %3.2f k\n', RC, RE);
    fprintf('gm  = %3.2f mS\n', gm);
    fprintf('rpi = %3.2f \n', rpi);
    fprintf('ro  = %3.2f k\n', ro);
    fprintf('Q-point(IC=%3.2f mA, VCE=%3.2f V)\n\n', IC, VCE);
    
    fprintf('DIFFERENTIAL-MODE\n');
    fprintf(' Gain Add \n  Add = %3.2f \n  Addn = %3.2f single\n', Add,Add/2);
    fprintf(' Output resistance\n  Rod = %3.2f k\n  Rodn = %3.2f k single\n', Rod, Rod/2);
    fprintf(' Input resistance \n  Rid = %3.2f k\n\n', Rid);
    
    fprintf('COMMON-MODE;\n Gain Acc\n  Acc = %3.2f\n', Acc);
    fprintf(' Input resistance\n  Ric = %3.2f k\n\n', Ric);
    
    fprintf('CMRR = %3.2f\n', CMRR);
    
%----------------------Part 2 --------------------
%Io =