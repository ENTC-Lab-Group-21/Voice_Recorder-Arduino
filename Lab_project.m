% closing previous windows and clearing wokspace---------------------------

close all;
clear all;

% Audio file
% Loading------------------------------------------------------------------

AudioFile = 'E:\songs\Ahankara_Nagare_-_Original__Ranidu_Lankage_Sarigama_lk-[AudioTrimmer.com].mp3'; % File name of audio file
[snd,fs] = audioread(AudioFile); % Reads sound file to snd and sampling freq to fs
%fs = 44100 samples/sec


%Scaling or pitch shifting-----------------------------------------------------------------------------
snd=resample(snd,1,2); %resample(x,p,q) resamples the input sequence, x, at p/q times the original sample rate


pt=30;% plotting time %30sec
N = fs*pt;%samples taken 
t = (0:N-1)/fs;

%Time domain representation--------------------------------------------
Xt = snd(1:N,1);

%frequency shifting-------------------------------------------------------
%f0=500;%shifting frequency(default f0=0)
%Xt=cos(2*pi*f0*t).*Xt;% exp(2*pi*f0*t)*x(t)

%filtering--------------------------------------------------------------------------------------------
fc=5000;
[b a] = butter(20,fc/25000, 'low');
Xt = filter(b,a,Xt);

% Normalize(Scale the output between -1,1)
nXt = Xt/max(abs(Xt));

subplot(2,1,1);
plot(t,nXt);
xlabel ('Time (s)');
ylabel ('Amplitude');
title ('Audio Signal (Time Domain)');
%----------------------------------------------------------------------



%Frequancy domain representation---------------------------------------

Xf = abs(fftshift(fft(Xt)));
f = (-N/2:N/2-1)*fs/N;

subplot(2,1,2);
plot(f,Xf);
xlabel ('Frequency (Hz)');
ylabel ('Magnitude');
title ('Audio Signal (Frequency Domain)');

