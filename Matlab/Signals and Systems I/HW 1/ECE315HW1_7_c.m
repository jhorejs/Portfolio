clear all;
%define time scale
t=0:0.01:5;

%part b
figure(1)
%real part of z(t)
realzt=4*exp(-t).*(cos(2*pi.*t));
%plot real part of z(t)
subplot(3,1,1);
plot(t,realzt);
xlabel('time(sec)');
ylabel('real part of z(t)');
title('Real part of z(t)');

%imaginary part of z(t)
imagzt=4*exp(-t).*(sin(2*pi.*t));
%plot imaginary part of z(t)
subplot(3,1,2);
plot(t,imagzt);
xlabel('time(sec)');
ylabel('imaginary part of z');
title('Imaginary part of z(t)');


%magnitude of z(t)
magzt=4*exp(-t);
%plot magnitude of z(t)
subplot(3,1,3);
plot(t,magzt);
xlabel('time(sec)');
ylabel('|z(t)|');
title('Magnitude of z(t)');

%part c
figure(2);
plot3(t,realzt,imagzt,'LineWidth',3,'Color','m');
grid on;
hold on;
plot3(t, realzt, zeros(size(t))-2,'Color','g');
plot3(t, zeros(size(t))-2, imagzt,'Color','r');
hold off;
view([-125 30])
xlabel('time (sec)', 'Rotation',-30);
ylabel('real part of z(t)', 'Rotation',10);
zlabel('imaginary part of z(t)');
legend('3D plot','2D projection - real(z(t))','2D projection - imag((z(t))');