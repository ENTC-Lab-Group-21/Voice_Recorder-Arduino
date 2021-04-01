% closing previous windows and clearing wokspace

close all;
clear all;


% Audio file Loading--------------------------------------------------
AudioFile = 'D:\soundfile\sound.wav'; % file name of audio file
[snd,fs] = audioread(AudioFile); % Reads sound file to snd and sampling freq to fs
%fs=16000 samples/sec

% Play sound
player = audioplayer(snd, fs);%give the same sampling rate
play(player);

pt=30;% plotting time %30sec
N = fs*pt; 
t = (1:N)/fs;

%Time domain representation--------------------------------------------
Xt = snd(1:N,1);

% Normalize(Scale the output between -1,1)
Xt = Xt/max(abs(Xt));

%subplot(2,1,1);
%plot(t,Xt);
xlabel ('Time (s)');
ylabel ('Amplitude');
title ('Audio Signal (Time Domain)');
%----------------------------------------------------------------------

%sound(Xt,fs);% play the part Xt under sampling rate of fs

%Frequancy domain representation---------------------------------------

Xf = abs(fft(Xt));
f = 1/pt:1/pt:fs;

%subplot(2,1,1);
plot(f(1:10*fs),Xf(1:10*fs)/max(abs(Xf(1:10*fs))));
xlabel ('Frequency (Hz)');
ylabel ('Magnitude');
title ('Audio Signal (Frequency Domain)');

