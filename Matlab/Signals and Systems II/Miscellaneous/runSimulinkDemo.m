% ECE 316: Simulink Demo
% April 15 2021
% Prof. Taisa Kushner

%Running a simulink model via Matlab

% the sim() command runs a simulink model simulation (passed as input), 
% we are saving the output as model_out, 
% and saying we want to "ReturnWorkspaceOutputs"
% this gives us a data structure with all the information
model_out = sim('simulink_demo_April15','ReturnWorkspaceOutputs','on');

%now we access our data and plot it
figure()
hold on
%plot the model output vs time 
plot(model_out.yout{1}.Values.Time, model_out.yout{1}.Values.Data)
set(gca,'FontSize',16)
xlabel('time','FontSize',16)
ylabel('x(t)','FontSize',16)
hold off
grid on

figure()
hold on
%plot the model output vs time 
stem(model_out.yout{1}.Values.Time, model_out.yout{1}.Values.Data)
%pzmap(model_out.yout{1}.Values.Time, model_out.yout{1}.Values.Data)
set(gca,'FontSize',16)
xlabel('time','FontSize',16)
ylabel('x(t)','FontSize',16)
hold off
grid on