clc;

Ws = tf ([0.1 0.1], [147.875 60.45 8.7 1]) % ������ �� ��'���� W(s)

step (Ws); % ��������� �������������� 
figure;  % ���� �������� ����
impulse (Ws) % ��������� ��������������


Ts=1.1 % ��� �������������
format long; % ������ ������ ������� �������� �������

Wpz = c2d (Ws, Ts, 'zoh')  % ����������� ��������� �� Wp(z) ��� {ZOH+W(s)}
% ������ 'zoh' �� ����������� 
Wpz.Numerator{1}   %���������
Wpz.Denominator{1} %���������

%[Num, Den] = tfdata (Wpz);
%bd=Num{1} %���������
%ad=Den{1} %���������


W_1_s = tf(1,[1 0]); % Wint(s)=1/s

Wztmp = c2d (Ws*W_1_s, Ts, 'impulse')  % z-������������ ���.������� W(s)/s ������� "impulse"
Wztmp.Numerator{1}   %���������
Wztmp.Denominator{1} %���������

%[Num, Den] = tfdata (Wztmp);
%bd=Num{1} %���������
%ad=Den{1} %���������


% ���������: 
[bzoh, R] = deconv(Wztmp.Numerator{1},[1 0]); 
 bzoh=bzoh/Ts
[azoh, R] = deconv(Wztmp.Denominator{1},[1 -1]);
azoh

format short; % ������ ������ ������� �� ����������� 