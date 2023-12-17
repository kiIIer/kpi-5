
% ======������ ��������� ==========
V=217;  T1=4;  T2=5;  q=0.2;  T3=1;  K1=0.5;  K2=0.1;  Un=80;  % ������ ��������� ������ ��������
K=35; % �������� K - ���� ������ ��������� � ������� ��������� ������ 
% =================================

clc; % �������� �����


Ts = 0.1* (T1 + T2 + T3);
disp (['������ �������������, ������ ��������: Ts=', num2str(Ts), ', ���.']);
fs = 1/Ts;
disp (['������� �������������  fs=1/Ts=', num2str(fs), ', ��.']);
fn = 0.5*fs;
disp (['������� ���������  fn=0.5*fs=', num2str(fn), ', ��.']);
disp (' ' );



b = K1*K2*[T3 1]
a = conv([T1 1], [T2*T2 2*T2*q 1])
%Wp = tf (K1*K2*[T3 1],  conv([T1 1], [T2*T2 2*T2*q 1]) )
Wp = tf (b,a)

bp = Wp.Numerator{1};
ap = Wp.Denominator{1};

disp( [ 'bp = [ ',num2str(bp,8), ' ]' ])
disp( [ 'ap = [ ',num2str(ap,8), ' ]' ])
disp( ['  ']);


% C2. ����������� ������������ ������� ��������� ������� � �-�����������
% �������� ��������� �� �������� 
bcs = K*bp;
acs = ap+K*bp;
disp( [ 'bcs = [ ',num2str(bcs,8), ' ]' ])
disp( [ 'acs = [ ',num2str(acs,8), ' ]' ])
disp (' ' );


% D1
% �������� ������������ ��������� ������������ �������� (ZOH+plant)
Wpzoh = c2d (Wp,Ts,'zoh') 
np = Wpzoh.Numerator{1};
mp = Wpzoh.Denominator{1};
disp( [ 'np = [ ',num2str(np,8), ' ]' ])
disp( [ 'mp = [ ',num2str(mp,8), ' ]' ])
disp( ['  ']);

%D2. ����������� ��������� ������������ ������� ��������� ������� � �-�����������
% �������� ��������� �� �������� 
ncs = K*np;
mcs = mp+K*np;
disp( [ 'ncs = [ ',num2str(ncs,8), ' ]' ])
disp( [ 'mcs = [ ',num2str(mcs,8), ' ]' ])
disp( '  ' );
disp( '  ' );

ps=roots (acs);
disp( [ '������ (������ ����������������� ��������) ����������� ��������� ������� ps:' ])
disp ([num2str(ps,5)])
disp( '  ' );


pz=roots (mcs);
Abspz = abs (pz);
disp( [ '������ (������ ����������������� ��������) ���������� ��������� ������� pz:' ])
disp ([num2str(pz,5)])
disp( '  ' );
disp( [ 'Abs (pz):' ])
disp ([num2str(Abspz,5)])




%nyquist (Wp,Wpzoh, K*Wp, K*Wpzoh); legend ('Wp','Wpzoh','K*Wp','K*Wpzoh')
nyquist (K*Wp, K*Wpzoh); legend ('K*Wp','K*Wpzoh')


%bode (Wp,Wpzoh); legend ('Wp','Wpzoh'); grid on

