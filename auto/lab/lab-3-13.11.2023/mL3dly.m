clc;
Ts=1.1 % ��� �������������
format long; % ������ ������ ������� �������� �������


Wsdly = tf ([0.1 0.1], [147.875 60.45 8.7 1],'IODelay',5) % W(s) � ��������� 5�

Wpzdly = c2d (Wsdly, Ts)  % ����� 'zoh' �� ����������� 
Wpzdly.Numerator{1}   %���������
Wpzdly.Denominator{1} %���������


Wsdly = tf ([0.1 0.1], [147.875 60.45 8.7 1],'IODelay',0.6) % W(s) � ��������� 0.6�

Wpzdly = c2d (Wsdly, Ts)  % ������ 'zoh' �� ����������� 
Wpzdly.Numerator{1}   %���������
Wpzdly.Denominator{1} %���������