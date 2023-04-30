clc
close all
clear
A =input ('Enter Amplitude:')
F =input ('Enter Frequency:')
t = 0:0.001:1
#sine Plot
y1 = A*sin(2*pi*F*t);
subplot(2,2,1)
plot(t,y1)
title('Sine Plot')
xlabel('time(t)')
ylabel('Amplitude')
#Cosine Plot
y2 = A*cos(2*pi*F*t);
subplot(2,2,2)
plot(t,y2)
title('Cosine Plot')
xlabel('time(t)')
ylabel('Amplitude')
#Square Plot
y3 = A*square(2*pi*F*t);
subplot(2,2,3)
plot(t,y3)
title('Square Plot')
xlabel('time(t)')
ylabel('Amplitude')
#Triangle Plot
y4 = A*sawtooth(2*pi*F*t,0.5);
subplot(2,2,4)
plot(t,y4)
title('Triangle Plot')
xlabel('time(t)')
ylabel('Amplitude')
