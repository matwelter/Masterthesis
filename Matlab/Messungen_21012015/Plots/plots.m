figure()
plot(t.dbg,p.hlcmd.x,'m', t.pos, p.lscn.x,'b', t.dbg, p.refmdl.x,'g', t.dbg, p.obs.x,'r');
         ylabel('x in m');
         xlabel('sec');
         legend('p_{cmd}','p_{laser}','p_{ref}','p_{beob}');
         
figure()
plot(t.dbg,-p.hlcmd.y,'m', t.pos, p.lscn.y,'b', t.dbg, -p.refmdl.y,'g', t.dbg, -p.obs.y,'r');
         ylabel('y in m');
         xlabel('sec');
         legend('p_{cmd}','p_{laser}','p_{ref}','p_{beob}');
         
figure()
plot(t.dbg,v.refmdl.x,'g',t.dbg,v.obs.x,'r');
         ylabel('v_x in m/s');
         xlabel('sec');
         legend('v_{ref}','v_{beob}');

figure()
plot(t.dbg,-v.refmdl.y,'g',t.dbg,-v.obs.y,'r');
         ylabel('v_y in m/s');
         xlabel('sec');
         legend('v_{ref}','v_{beob}');
         
figure()         
plot(t.curpos,ori.curpos.pitch+0.025,'k',t.dbg,-cmdLL.pitch,'m');
          ylabel('rad');
          xlabel('sec');
         legend('theta_{ist}','theta_{inversion}');
         
figure()         
plot(t.curpos,ori.curpos.roll+.02,'k',t.dbg,cmdLL.roll+0.06,'m');
          ylabel('rad');
          xlabel('sec');
         legend('phi_{ist}','phi_{inversion}');  
         
  eins3 = max(find(t.dbg<33));
  
figure('Name','xy Positionen');
    plot(p.refmdl.x(1:eins3),-p.refmdl.y(1:eins3),'g', p.obs.x(1:eins3), -p.obs.y(1:eins3),'r',p.refmdl.x(1),-p.refmdl.y(1),'o',p.refmdl.x(eins3),-p.refmdl.y(eins3),'x');
            xlabel('x in m');
            ylabel('y in m');
            legend('p_{ref}','p_beob','p_{start}','p_{ende}'); 