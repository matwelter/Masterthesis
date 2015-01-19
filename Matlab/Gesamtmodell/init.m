
%% Translationsmdl
m = 1.863;
g = 9.81;
% bias = [1;0;0.5];
bias = [0;0;0];

%% Beobachter
% l_1 = 8; 
% l_2 = 15.18;
% l_3 = 25.45;
l_1 = 8; 
l_2 = 10.18;
l_3 = 25.45;

%% Referenzmodell
omega_0 = 1.5;
xi      = 1;

%% Folgeregler
% Kd = 15;
% Kp = 20;
% Ki = 5;
Kd = 4;
Kp = 5;
Ki = 0.01;
% Kd = 6;
% Kp = 1.2;
% Ki = 0.06
sim('gesamtmodell')

figure('Name','ref_vor_id');
    plot(P.time,P.signals.values(:,1),P_ref.time,P_ref.signals.values(:,1),'g',P_mdl.time,P_mdl.signals.values(:,1),'r');
            xlabel('sec');
            ylabel('m');
            legend('p_{cmd}','p_{ref}','p_{mdl}');

