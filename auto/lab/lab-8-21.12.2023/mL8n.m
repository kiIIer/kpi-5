clc;

%=======================================================================================================
%=======================================================================================================
V=217;  T1=4;  T2=5;  q=0.2;  T3=1;  K1=0.5;  K2=0.1;  Un=80;  % ������ ��������� ������ ��������
%=======================================================================================================
Fpoles  = [0.42;0.55;0.63];  % ������� ������ ������ ������� ��� ���������� ����������.
%Fpoles = [0; 0; 0] %max speed
Lpoles  = [0.11; 0.24; 0.26];  % ������� ������ ������ ������� ��� ��������������� �������� .
%Lpoles = [0; 0; 0] %max speed


%=======================================================================================================
%=======================================================================================================




disp (['---------LR8---------'])
disp (['V=', num2str(V) ]);

PrntT1 = ['T1=', num2str(T1), ';  '];
PrntT2 = ['T2=', num2str(T2), ';  '];
Prntq  = ['q=',  num2str(q),  ';  '];
PrntT3 = ['T3=', num2str(T3), ';  '];
PrntK1 = ['K1=', num2str(K1), ';  '];
PrntK2 = ['K2=', num2str(K2), ';  '];
PrntUn = ['Un=', num2str(Un), ';  '];

disp ([PrntT1, PrntT2, Prntq, PrntT3, PrntK1, PrntK2, PrntUn]);


Ts = 0.1* (T1 + T2 + T3); % Ts ������ ������� �������
disp (['������ �������������, ������ ��������: Ts=', num2str(Ts), ', ���.']);

%Wengine
be0 = K1/T1;
ae0 = 1/T1;

%
bp1 = T3 / (T2*T2);
bp0 = 1 / (T2*T2);


ap2 = 1;
ap1 = 2*q / T2;
ap0 = 1 / (T2*T2);


b1 = be0*K2*bp1;
b0 = be0*K2*bp0;


a3 = 1;
a2 = ae0+ap1;
a1 = ae0*ap1 + ap0;
a0 = ae0*ap0;


Wengine = tf ([be0], [1 ae0]);
%disp( [ 'num = [ ',num2str(Wengine.Numerator{1},4), ' ]' ])
%disp( [ 'dnm = [ ',num2str(Wengine.Denominator{1},5), ' ]' ])

Wplant =  tf ([b1 b0], [1 a2 a1 a0]);
%disp( [ 'num = [ ',num2str(Wplant.Numerator{1},4), ' ]' ])
%disp( [ 'dnm = [ ',num2str(Wplant.Denominator{1},5), ' ]' ])

Wzoh_plant = c2d (Wplant,Ts);
%disp( [ 'num = [ ',num2str(Wzoh_plant.Numerator{1},8), ' ]' ])
%disp( [ 'dnm = [ ',num2str(Wzoh_plant.Denominator{1},8), ' ]' ])


n3 = Wzoh_plant.Numerator{1}(1); % n3=0 !!!
n2 = Wzoh_plant.Numerator{1}(2);
n1 = Wzoh_plant.Numerator{1}(3);
n0 = Wzoh_plant.Numerator{1}(4);

m3 = Wzoh_plant.Denominator{1}(1); % m3=1 !!!
m2 = Wzoh_plant.Denominator{1}(2);
m1 = Wzoh_plant.Denominator{1}(3);
m0 = Wzoh_plant.Denominator{1}(4);


%[Ac,Bc,Cc,Dc] = tf2ss ([b1 b0], [a3 a2 a1 a0])
%[Ad,Bd,Cd,Dd] = tf2ss ([n2 n1 n0], [m3 m2 m1 m0])


% ������� ����� �������� ����������:
Ac = [  0   1   0 ; 
        0   0   1 ;  
       -a0 -a1 -a2 ];
    
Bc = [  0 ; 
        0 ; 
        1 ];
    
Cc = [ b0   b1   0 ] ;

Dc = 0;

% ��� � ���� ������:
Ad = [ 0 1 0 ; 0 0 1 ;  -m0  -m1  -m2 ];
Bd = [ 0 ; 0 ; 1 ];
Cd = [ n0   n1   n2 ];
Dd = 0;

%disp( ' ');
%disp( 'Ac = ');
%disp( num2str(Ac,4));
%disp( ' ');
%disp( 'Bc = ')
%disp( num2str(Bc,4))
%disp( ' ');
%disp( 'Cc = ')
%disp( num2str(Cc,4))
%disp( ' ');
%disp( 'Dc = ')
%disp( num2str(Dc,4))
%disp( ' ');

disp( ' ');
disp( 'Ad = ');
disp( num2str(Ad,5));
disp( ' ');
disp( 'Bd = ')
disp( num2str(Bd,5))
disp( ' ');
disp( 'Cd = ')
disp( num2str(Cc,5))
disp( ' ');
disp( 'Dd = ')
disp( num2str(Dc,5))

disp( '  ')
disp( '=========================== ')


%xc0 = - inv(Ac)*Bc*Un
%yc0 =  - Cc*inv(Ac)*Bc*Un

E = eye(3);
%xd0 = inv(E-Ad)*Bd*Un
%yd0 = Cd*inv(E-Ad)*Bd*Un


% =====================================================================
% MIMO
% =====================================================================


% CSS engine
Ae = [ -ae0];
Be = [ 1 ];
Ce = [ be0];
De = 0;

% CSS pump
Ap  = [ 0 1 ;  -ap0  -ap1 ];
Bpf = [ 0 ; 1 ];
Bpr = [ 0 ; K2 ];
Cp  = [ bp0   bp1  ];
Dp  = [0 0];


% CSS MIMO plant

Acm = [ Ae,         0, 0; 
        Bpr*Ce,      Ap  ];
    
Bcm = [[0; Bpf],  [Be; 0; 0] ];

Ccm = [[0 Cp]; [Ce 0 0]];


% =====================================================================
% ss(), c2d()
% =====================================================================


%Css   = ss(Ac,Bc,Cc,Dc);
%ZOHss = c2d(Css,Ts);


Kg=1/(K1*K2);

%F=acker (Ad,Bd,[0.31; 0.42; 0.82])
F=acker (Ad,Bd,Fpoles);

pmr_ust=Cd*inv(E-Ad+Bd*F)*Bd;
K=1/pmr_ust;

%L=acker(Ad',Cd', [0.11; 0.21; 0.26])'
L=acker(Ad',Cd', Lpoles)' ;

CSS_Ws = ss(Ac,Bc,Cc,Dc);
SSd = c2d (CSS_Ws ,Ts);

Ktfz = (1+m2+m1+m0)/(n2+n1+n0);

% ������� ����� �������:
As = [ Ad, -Bd*F; L*Cd, (Ad - L*Cd - Bd*F)];
eig (As);

disp( ' ');
disp( 'K = ');
disp( num2str(K,5))
disp( ' ');
disp( 'Kg = ');
disp( num2str(Kg,5))
disp( ' ');
disp( 'F = ');
disp( num2str(F,5))
disp( ' ');
disp( 'L = ');
disp( num2str(L,5))



