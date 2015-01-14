close all;

figure('Name','Eingangsgröße');
    plot(u_besch_at_ab.time,u_besch_at_ab.signals.values),title('Eingansgrößen');
            xlabel('sec');
            ylabel('m/s^2');
         legend('Translationsmodell','Beobachter');
   
figure('Name','Bias');
    plot(bias_offs_beo.time,bias_offs_beo.signals.values),title('Bias');
            xlabel('sec');
            ylabel('m/s^2');
         legend('Sensoroffset','Beobachter'); 
         
         
figure('Name','Beschleunigung');
    plot(beschl_at_ab.time,beschl_at_ab.signals.values),title('Beschleunigung');
            xlabel('sec');
            ylabel('m/s^2');
         legend('Translationsmodell','Beobachter'); 
         
         
figure('Name','Geschwindigkeit');
    plot(geschw_vt_vb.time,geschw_vt_vb.signals.values),title('Geschwindigkeit');
            xlabel('sec');
            ylabel('m/s');
         legend('Translationsmodell','Beobachter'); 
         
figure('Name','Position');
    plot(pos_pt_pb.time,pos_pt_pb.signals.values),title('Position');
            xlabel('sec');
            ylabel('m');
         legend('Translationsmodell','Beobachter','40Hz Updaterate'); 
         
    