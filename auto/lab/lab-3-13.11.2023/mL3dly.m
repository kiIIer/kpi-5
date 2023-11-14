clc;
Ts=1.1 % час дискретизації
format long; % формат виводу значень підвищеної точності


Wsdly = tf ([0.1 0.1], [147.875 60.45 8.7 1],'IODelay',5) % W(s) з затримкою 5с

Wpzdly = c2d (Wsdly, Ts)  % метод 'zoh' за замовченням 
Wpzdly.Numerator{1}   %чисельник
Wpzdly.Denominator{1} %знаменник


Wsdly = tf ([0.1 0.1], [147.875 60.45 8.7 1],'IODelay',0.6) % W(s) з затримкою 0.6с

Wpzdly = c2d (Wsdly, Ts)  % зметод 'zoh' за замовченням 
Wpzdly.Numerator{1}   %чисельник
Wpzdly.Denominator{1} %знаменник