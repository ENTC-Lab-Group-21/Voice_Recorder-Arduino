close all; %closing all windows

% generate the signal......................................................
frequancy = [5 10 15 20 25 30 35 40 45 50 ];
delta0 = 0.001;
time_dom = -2:delta0:2-delta0;
sample_signal = zero_arr(length(time_dom));
for j=1:length(time_dom)
    sample_signal(j) = 1.3+2*sin(2*pi*frequancy(1)*time_dom(j))+1.8*sin(2*pi*frequancy(2)*time_dom(j))+0.5*sin(2*pi*frequancy(3)*time_dom(j))+0.4*sin(2*pi*frequancy(4)*time_dom(j))+1.4*sin(2*pi*frequancy(5)*time_dom(j))+0.8*sin(2*pi*frequancy(6)*time_dom(j))+sin(2*pi*frequancy(7)*time_dom(j))+sin(2*pi*frequancy(8)*time_dom(j))+sin(2*pi*frequancy(9)*time_dom(j))+2*sin(2*pi*frequancy(10)*time_dom(j));
end
figure;
fs = 1000;
f1 = -fs/2:fs/3999:(fs/2);
y1=my_fftshift(abs(my_fft(sample_signal,4000)));
plot(f1,y1);
xlabel("Frequency (Hz)");
ylabel("Amplitude");
title("Original signal");
grid();
xlim([-100,100]);

%filtering.................................................................

fil_fre = 15;
delta1 = 0.001;
t=-2:delta1:(2-delta1);
w = 2*pi*fil_fre/3;
sinc_signal = sinc(w.*t);
filtered = my_convolve(sample_signal,sinc_signal);
fs = 1000;
f2 = -fs/2:fs/7998:(fs/2);
y2=my_fftshift(abs(my_fft(filtered,7999)));
figure;
plot(f2,y2);
xlabel("Frequency (Hz)");
ylabel("Amplitude");
title("Filtered signal");
grid();
xlim([-100,100]);



%frequancy scale...........................................................
scaled_signal = zero_arr(length(time_dom));
factor = 2;
for j=1:length(time_dom)
    scaled_signal(j) = 1.3+2*sin(factor*2*pi*frequancy(1)*time_dom(j))+1.8*sin(factor*2*pi*frequancy(2)*time_dom(j))+0.5*sin(factor*2*pi*frequancy(3)*time_dom(j))+0.4*sin(factor*2*pi*frequancy(4)*time_dom(j))+1.4*sin(factor*2*pi*frequancy(5)*time_dom(j))+0.8*sin(factor*2*pi*frequancy(6)*time_dom(j))+sin(factor*2*pi*frequancy(7)*time_dom(j))+sin(factor*2*pi*frequancy(8)*time_dom(j))+sin(factor*2*pi*frequancy(9)*time_dom(j))+2*sin(factor*2*pi*frequancy(10)*time_dom(j));
end
figure;
fs = 1000;
f3 = -fs/2:fs/3999:(fs/2);
y3=my_fftshift(abs(my_fft(scaled_signal,4000)));
plot(f3,y3);
xlabel("Frequency (Hz)");
ylabel("Amplitude");
title("Scaled signal");
grid();
xlim([-100,100]);

%frequency shift...............................
fshift=50;
val = exp(1i*2*pi*fshift*time_dom);
shifted = val.*sample_signal;
figure;
fs = 1000;
f4 = -fs/2:fs/3999:(fs/2);
y4=abs(my_fft(shifted,4000));
p= y4((fshift)*4:(fshift+50)*4);
sz = zero_arr((450-fshift)*4);
mz = zero_arr((fshift-1)*8);
p1 = [ 0 0 0 sz flip(p) mz p sz 0 0 0];
plot(f4,p1,"g");
xlabel("Frequency (Hz)");
ylabel("Amplitude");
title("Shifted signal");
grid();
xlim([-100,100]);


%FFt function........................................................
function z = my_fft(x,num_fft)
N = length(x);
z = zeros(1,num_fft);
sum=0;
for k = 1:num_fft
    for jj = 1:N
        sum = sum + x(jj)*exp(-2i*pi*(jj-1)*(k-1)/num_fft);
    end
    z(k) = sum;
    sum = 0;
end
return 
end

%abs_value function......................................................



%my_fft_shift function.............................................
function s = my_fftshift(vec)
l = length(vec);
if(mod(l,2)==0)
    s = [vec(l/2+1:l),vec(1:l/2)];
end
if(mod(l,2)~=0)
    s = [vec((l+1)/2+1:l),vec(1:(l+1)/2)];
end  
return
end


%my_convolve function...........................................
function Y= my_convolve(x, h)
m = length(h);
n = length(x);
Ny = m+n-1;
Y = zero_arr(Ny);
for i = 1:n
    for k = 1:m
        Y(i+k-1) = Y(i+k-1)+h(k)*x(i);
    end
end 
return
end

%zeroes function implementation........................................
function z = zero_arr(n)
z=[0,0];
for g = 3:n
    z (g) = 0;
end
end
