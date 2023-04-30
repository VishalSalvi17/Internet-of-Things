clc
close all
clear
t=0:0.001:2;
s=sawtooth(4*pi*10*t+(pi/2),0.5);
m=0.80*sin(4*pi*1*t);
n=length(s);
for i=1:n
  if(m(i)>=s(i))
  pwm(i)=1;
  elseif(m(i)<=s(i))
  pwm(i)=0;
end
end

#Sine-Triangle wave
subplot(2,1,1)
plot(t,m,'-k',t,s,'-r');
axis([0 2 -1.5 1.5]);
title('Sine triangle wave');
xlabel('time');
ylabel('Voltage');

#PWM Wave
subplot(2,1,2)
plot(t,pwm,'-b');
axis([0 2 -1.5 1.5]);
title('PWM wave');
xlabel('time');
ylabel('Voltage');