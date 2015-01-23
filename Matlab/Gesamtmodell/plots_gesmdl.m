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
            
%% Für Kapitel Simulation Gesamtmodell            
  %Pos x          
        figure('Name','Positionen ');
    plot(P_40.time,P_40.signals.values(:,1),'b',P_bo.time,P_bo.signals.values(:,1),'r',P.time,P.signals.values(:,1),'m',P_ref.time,P_ref.signals.values(:,1),'g');
            xlabel('sec');
            ylabel('m');
            legend('p_{40Hz}','p_{beob}','p_{cmd}','p_{ref}');    
            
    %Pos y        
            figure('Name','Positionen ');
    plot(P_40.time,P_40.signals.values(:,2),'b',P_bo.time,P_bo.signals.values(:,2),'r',P.time,P.signals.values(:,2),'m',P_ref.time,P_ref.signals.values(:,2),'g');
            xlabel('sec');
            ylabel('m');
            legend('p_{40Hz}','p_{beob}','p_{cmd}','p_{ref}');   
            
    %V x
    
      figure('Name','Geschwindigkeit');
    plot(V_bo.time,V_bo.signals.values(:,1),'r',V_ref.time,V_ref.signals.values(:,1),'g');
            xlabel('v_x in m/sec');
            ylabel('m');
            legend('v_{beob}','v_{ref}');
            
     %V x
    
      figure('Name','Geschwindigkeit');
    plot(V_bo.time,V_bo.signals.values(:,2),'r',V_ref.time,V_ref.signals.values(:,2),'g');
            xlabel('sec');
            ylabel('v_y in m/s');
            legend('v_{beob}','v_{ref}');       
            
     %Ori       
            
   figure('Name','Winkel');
    plot(out_invers.time,out_invers.signals.values(:,2),'k');
            xlabel('sec');
            ylabel('rad');
            legend('phi');   
   
   figure('Name','Winkel');
    plot(out_invers.time,out_invers.signals.values(:,3),'k');
            xlabel('sec');
            ylabel('rad');
            legend('theta');            
            
  %% xy 
  % xy ref
  P_ref.time,P_ref.signals.values(:,1),'g'
            
               figure('Name','xy Positionen');
    plot(P_ref.signals.values(:,1),P_ref.signals.values(:,2),'g',P_bo.signals.values(:,1),P_bo.signals.values(:,2),'r',P_ref.signals.values(1,1),P_ref.signals.values(1,2),'o',P_ref.signals.values(end,1),P_ref.signals.values(end,2),'x');
            xlabel('x in m');
            ylabel('y in m');
            legend('p_{ref}','p_beob','p_{start}','p_{ende}');        