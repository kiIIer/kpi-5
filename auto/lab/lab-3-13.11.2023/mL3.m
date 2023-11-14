clc;

Ws = tf ([0.1 0.1], [147.875 60.45 8.7 1]) % задана ПФ об'єкта W(s)

step (Ws); % перехідна характеристика 
figure;  % нове графічне вікно
impulse (Ws) % імпульсна характеристика


Ts=1.1 % час дискретизації
format long; % формат виводу значень підвищеної точності

Wpz = c2d (Ws, Ts, 'zoh')  % знаходження дискретної ПФ Wp(z) для {ZOH+W(s)}
% зметод 'zoh' за замовченням 
Wpz.Numerator{1}   %чисельник
Wpz.Denominator{1} %знаменник

%[Num, Den] = tfdata (Wpz);
%bd=Num{1} %чисельник
%ad=Den{1} %знаменник


W_1_s = tf(1,[1 0]); % Wint(s)=1/s

Wztmp = c2d (Ws*W_1_s, Ts, 'impulse')  % z-перетворення доп.функції W(s)/s методом "impulse"
Wztmp.Numerator{1}   %чисельник
Wztmp.Denominator{1} %знаменник

%[Num, Den] = tfdata (Wztmp);
%bd=Num{1} %чисельник
%ad=Den{1} %знаменник


% спрощення: 
[bzoh, R] = deconv(Wztmp.Numerator{1},[1 0]); 
 bzoh=bzoh/Ts
[azoh, R] = deconv(Wztmp.Denominator{1},[1 -1]);
azoh

format short; % формат виводу значень за замовченням 