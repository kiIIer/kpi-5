% �������� ���������
% ��������� ���� ������������ ������� ��������� ������� 
% W(z) = ncs(z) / mcs(z)

K=20;

ncs = K*np;
mcs = mp+K*np;

j=sqrt (-1); 
w=0:0.005:pi;

Wjw = polyval (mcs, exp(j*w));

% ���������� �� �������� :)
Wjwn = Wjw ./  (abs(Wjw)+0.05); % �� ������� �����������!!! :) :) :)

x  = real (Wjw);
y  = imag (Wjw);

xn = real (Wjwn);
yn = imag (Wjwn);


clf;

f1=figure (1);
plot (x,y, 0,0,'r*')
title (['�������� ��������.  K=', num2str(K)])

f2=figure (2);
plot (xn, yn, 0,0,'r*')
title (['�������� �������� mod KPI.   K=', num2str(K)])


clc;
pz=roots (mcs);
Abspz = abs (pz);
disp( [ '������ (������ ����������������� ��������) ���������� ��������� ������� pz:' ])
disp ([num2str(pz,5)])
disp( '  ' );
disp( [ 'Abs (pz):' ])
disp ([num2str(Abspz,5)])