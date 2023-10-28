

y=[ 1,   0,   0,     0,   0,   0,   0,   0,   0,   0,   0];
u=[ 0.7, -0.3, 0.2,   0,   0,   0,   0,   0,   0,   0,   0];
n=0:10; % n = [0, 1, 2, ..., 10]


clf; clc;   
subplot(2,1,1);
stem (n,u,'ro')
xlabel ('n');
ylabel ('u[n]');

subplot(2,1,2); 
stem (n,y,'go')
xlabel ('n');
ylabel ('y[n]');


