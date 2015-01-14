close all;

figure('Name','a_soll_n');
    plot(a_soll_n.time,a_soll_n.signals.values);
            xlabel('sec');
            ylabel('m/s^2');
         legend('u_{f1}=a_{nxs}','u_{f2}=a_{nys}','u_{f3}=a_{nzs}');
         
figure('Name','psi');
    plot(psi.time,psi.signals.values);
            xlabel('sec');
            ylabel('rad');
         legend('theta = u_4');
         
figure('Name','a_soll_o');
        plot(a_soll_o.time,a_soll_o.signals.values);
            xlabel('sec');
            ylabel('m/s^2');
          legend('a_{oxs}','a_{oys}','a_{ozs}');
          
figure('Name','Inversion T');
        plot(out_invers.time,out_invers.signals.values(:,1));
            xlabel('sec');
            ylabel('N');
          legend('T = u_1');
          
figure('Name','Inversion phi und theta');
        plot(out_invers.time,out_invers.signals.values(:,2:end));
            xlabel('sec');
            ylabel('rad');
          legend('phi = u_2','theta = u_3');
          
          figure('Name','a_mdl_n');
    plot(a_soll_n.time,a_soll_n.signals.values);
            xlabel('sec');
            ylabel('m/s^2');
         legend('a_{nx}','a_{ny}','a_{zs}');