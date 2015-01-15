close all;
%% Referenzmdl
figure('Name','Soll-Position');
    plot(P.time,P.signals.values(:,1));
            xlabel('sec');
            ylabel('m');
            legend('p_{cmd}');

figure('Name','Ref-Position');
    plot(P_ref.time,P_ref.signals.values(:,1),'g');
            xlabel('sec');
            ylabel('m');
            legend('p_{ref}');
            
figure('Name','Soll/Ref-Position');
    plot(P.time,P.signals.values(:,1),P_ref.time,P_ref.signals.values(:,1),'g');
            xlabel('sec');
            ylabel('m');
            legend('p_{cmd}','p_{ref}');            

figure('Name','Ref-Geschwindikeit');
    plot(V_ref.time,V_ref.signals.values(:,1),'g');
            xlabel('sec');
            ylabel('m/s');
            legend('v_{ref}');
figure('Name','Ref-Beschleunigung');
    plot(A_ref.time,A_ref.signals.values(:,1),'g');
            xlabel('sec');
            ylabel('m/s^2');
            legend('u_{fref} = a_{ref}');
%% Referentmodell als Vorsteuerung 
figure('Name','ref_vor_id');
    plot(P.time,P.signals.values(:,1),P_ref.time,P_ref.signals.values(:,1),'g',P_mdl.time,P_mdl.signals.values(:,1),'r');
            xlabel('sec');
            ylabel('m');
            legend('p_{cmd}','p_{ref}','p_{mdl}');