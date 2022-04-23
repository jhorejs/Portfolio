clear;
file = fopen('BJT_amp_calc_results.txt', 'w');

%Transistor parameters 
Av = 165;
B = 300;
VBE = 0.7;

%Amp parameters
Rc = 20000;
Rin = 7500;
Vcc = 12;
VEE = 0;
VCE = 6;

Ic = Vcc/Rc;
gm = 40 * Ic;
rpi = B/gm;
RE = (((gm*Rc)/Av) - 1) / gm;
IB = Ic / B;
IE = (B + 1) * IB;
v = 12 - VCE;
R4 = (v/IE) - RE;
Rib = rpi * (1+ gm * RE);
RB = ((1/Rin) - (1/Rib))^(-1);
VEQ = IB * RB + VBE + IE * (RE + R4) - VEE;
R2 = abs(RB / ((VEQ + VEE) / (Vcc + VEE)));
R1 = abs(((1/RB) - (1/R2))^(-1));

%prints the reults to the command window and text file for coppying to
%LTspice
if Rib < Rin
    fprintf('Rib < Rin\n');
    fprintf(file, 'Rib < Rin\n');
else
    fprintf('Rc = %f\n', Rc);
    fprintf('RE = %f\n', RE);
    fprintf('R4 = %f\n', R4);
    fprintf('R2 = %f\n', R2);
    fprintf('R1 = %f\n', R1);
    fprintf('Q-point(%f, %f)\n\n', Ic, VCE);

    fprintf(file, '.param rc %f\n', Rc);
    fprintf(file, '.param re %f\n', RE);
    fprintf(file, '.param r4 %f\n', R4);
    fprintf(file, '.param r2 %f\n', R2);
    fprintf(file, '.param r1 %f\n', R1);
end


