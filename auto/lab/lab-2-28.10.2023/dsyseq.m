
% Рівняння виду
% y[n] = b0*u[n] + b1*u[n-1] + b2*u[n-2] - a1*y[n-1] - a2*y[n-2]
% 
% Передавальна функція:
%          b0*z^2 + b1*z + b2 
% W(z) = -----------------------
%             z^2 + a1*z + a2

% FIR
% b0=0.5; b1=-0.3; b2=0.3;
%         a1=0;    a2=0;

% IIR
  b0=2;  b1=0;   b2=0;
         a1=-0.6; a2=0.6;


u=[ 0.5,   -0.3,   0.3,     0,   0,   0,   0,   0,   0,   0,   0];


% початкові умови для n=0
un1 = 0; % u[n-1]=u[-1]=
un2 = 0; % u[-2]=
yn  = 0; % y[0]=
yn1 = 0; % y[-1]=
yn2 = 0; % y[-2]=

%================================================================================

y=zeros (1,11);
clc;

for n=0:10
    un=u(n+1); %MatLab індекси з 1 :( , тому u[0] в MatLab u(1), а u[n]=u(n+1)
    
    % TEXT BLOCK
        prnt_n  = ['n=',num2str(n)];
        prnt_un = ['u[n]=', num2str(un) ];
        prnt_un1= ['u[n-1]=', num2str(un1)];
        prnt_un2= ['u[n-2]=', num2str(un2)];
        prnt_yn1= ['y[n-1]=', num2str(yn1)];
        prnt_yn2= ['y[n-2]=', num2str(yn2)];
    
        disp (['---------',prnt_n,'---------'])
        disp (['Input:  ',prnt_un]);
        disp ([prnt_un1,';  ',prnt_un2]);
        disp ([prnt_yn1,';  ',prnt_yn2]);
    % TEXT BLOCK
    
    % Calc Eq:
    [yn,yn1,yn2,un1,un2] = deq (un, un1, un2, yn1, yn2, b0, b1, b2, a1, a2);
    
    % TEXT BLOCK
        prnt_yn = ['y[n]=', num2str(yn) ];
        disp (['...Calc...'])
        pause (0.2);
        disp (['Output: ',prnt_yn]);
        pause (0.8);
    % TEXT BLOCK
    
    y(n+1)=yn;
end

n=0:10;

% Будуємо графік u[n],y[n]
clf;    
subplot(2,1,1);
stem (n,u,'ro')
xlabel ('n');
ylabel ('u[n]');

subplot(2,1,2); 
stem (n,y,'go')
xlabel ('n');
ylabel ('y[n]');





function [yn,yn1,yn2,un1,un2] = deq (un, un1, un2, yn1, yn2, b0, b1, b2, a1, a2)
% y[n] = b0*u[n] + b1*u[n-1] + b2*u[n-2] - a1*y[n-1] - a2*y[n-2]
  
  yn = b0*un + b1*un1 + b2*un2 - a1*yn1 - a2*yn2;
  
  % затримка входів на 1 такт
  un2=un1;
  un1=un;
  
  % затримка виходів на 1 такт
  yn2=yn1;
  yn1=yn;
  
end
