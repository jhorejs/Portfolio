%% Problem 6.a
clc; clear all;
s = tf('s');
%G_loop = 1/((s^2)*5.6e-8+s*4.54e-5+1);
G_loop = 1/((s/4225.77)^2+(2*.0473*s/4224.77)+1)
figure(1)
margin(G_loop)
h = gcr;
h.AxesGrid.Xunits = 'Hz';
h.AxesGrid.TitleStyle.FontSize=12;
h.AxesGrid.XLabelStyle.FontSize=12;
h.AxesGrid.YLabelStyle.FontSize=12;
Gm_dB = 20*log_10(G_loop)

%% Problem 6.b
s = tf('s');
G_vg = 0.5/((s^2)*5.6e-8+s*4.54e-5+1);
figure(2)
margin(G_vg)
h = gcr;
h.AxesGrid.Xunits = 'Hz';
h.AxesGrid.TitleStyle.FontSize=12;
h.AxesGrid.XLabelStyle.FontSize=12;
h.AxesGrid.YLabelStyle.FontSize=12;


%% Problem 6.c
clc; clear all;
s = tf('s');
Z = -((s*560e-6+230e-3)/((s^2)*5.6e-8+s*4.54e-5+1));
figure(3)
margin(Z)
h = gcr;
h.AxesGrid.Xunits = 'Hz';
h.AxesGrid.TitleStyle.FontSize=12;
h.AxesGrid.XLabelStyle.FontSize=12;
h.AxesGrid.YLabelStyle.FontSize=12;



%% Problem 6.d

Vg = 10; 
D = 0.5;
V = Vg * D;
s = tf('s')
Gvg = D*(1 / ( ( s^2 )*(5.6*10^-8)+s*(4.54*10^-5)+1));
t = linspace(0.02, 0.06, 1000);
u = zeros(size(t));
ind = find(t>=0.025 & t<=0.04);

Vg_diff = 1;
u(ind) = u(ind) + Vg_diff;
figure(4)
y = lsim(Gvg,u,t);
plot(t,y+V)
ylabel('V')
xlabel('t')
del_v = max(y) - min(y)
SSE = y(ind(end))


%% Problem 6.e
clc; clear all; 
s = tf('s'); 
Zout = -((s*560e-6+230e-3)/((s^2)*5.6e-8+s*4.54e-5+1));
Vg = 10; 
D = 0.5;
V = Vg * D;
Io_1 = V/25;
Io_2 = V/5; 
Io_diff = Io_2-Io_1;
t = linspace(0.02,0.06,1000);
u = zeros(size(t));
ind = find(t>=0.025 & t<=0.04);
u(ind) = u(ind) + Io_diff;
figure(5)
y = lsim(-Zout,u,t);
plot(t,y+V)
ylabel('V')
xlabel('t')
del_V2 = max(y)-min(y)
SSE2 = y(ind(end))
