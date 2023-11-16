V=217;  T1=4;  T2=5;  q=0.2;  T3=1;  K1=0.5;  K2=0.1;  Un=80;

bp = K1*K2*[T3 1]
ap = conv([T1 1], [T2*T2 2*T2*q 1])

bp1 = 1
ap1 = [T1 1]

bp2 = K1*K2*[T3 1]
ap2 = [T2*T2 2*T2*q 1]


W1p = tf (1 , [T1 1])
W2p = K1 * tf ( K2*[T3 1] , ap2) 

Wp = W1p*W2p
disp( [ 'num = [ ',num2str(Wp.Numerator{1},8), ' ]' ])
disp( [ 'dnm = [ ',num2str(Wp.Denominator{1},8), ' ]' ])

disp (' ' );

Ts = 0.1* (T1 + T2 + T3);
disp (['����� �������������, ����� �������: Ts=', num2str(Ts), ', ���.']);

fs = 1/Ts;
disp (['������� �������������  fs=1/Ts=', num2str(fs), ', ��.']);

fn = 0.5*fs;
disp (['������� ��������  fn=0.5*fs=', num2str(fn), ', ��.']);

f=[0.05 0.1 0.2 0.5 1 1.05]*fs
disp (['������� ��� ������������ f=[', num2str(f,5), '], ��.']);

Wpzoh = c2d (Wp,Ts,'zoh')
disp( [ 'num = [ ',num2str(Wpzoh.Numerator{1},8), ' ]' ])
disp( [ 'dnm = [ ',num2str(Wpzoh.Denominator{1},8), ' ]' ])

Wpbln = c2d (Wp,Ts,'tustin')
disp( [ 'num = [ ',num2str(Wpbln.Numerator{1},8), ' ]' ])
disp( [ 'dnm = [ ',num2str(Wpbln.Denominator{1},8), ' ]' ])

bode (Wp,Wpzoh,Wpbln); legend ('Wp','Wpzoh','Wpbln')

figure
nyquist (Wp,Wpzoh,Wpbln); legend ('Wp','Wpzoh','Wpbln')