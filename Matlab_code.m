close all; %closing all windows

%Audio files
file_1 = "africa-toto.wav";
%file_2 = "E:\songs\Ahankara_Nagare_-_Original__Ranidu_Lankage_Sarigama_lk-[AudioTrimmer.com].mp3";

%Reading the audio file
[snd,fs] = audioread(file_1,[1*22050, 2*22050]);

%plotting the original signal
figure;
subplot(4,1,1);
show_plot(snd, length(snd), fs, "Original signal");

%Scaling or pitch shifting-----------------------------------------------------------------------------
resam_snd = resample(snd,1,3); %resample(x,p,q) resamples the input sequence, x, at p/q times the original sample rate
subplot(4,1,2);
show_plot(resam_snd, length(resam_snd), fs, "Pitch Shifted signal");

%high-pass filter
fc=100;
high_passed = highpass(snd, fc, fs);
subplot(4,1,3);
show_plot(high_passed, length(high_passed), fs, "High-Pass filtered signal");

%Band-pass filter
band_passed = bandpass(snd, [500 1500], fs);
subplot(4,1,4);
show_plot(band_passed, length(band_passed), fs, "Band-Pass filtered signal");


sgtitle("Amplitude Spectrum");

%Freqency shifting----------------------------------------------------------------------------------------
subplot(5,1,5);
f0 = 1000;
w0 = 2*pi*f0;
t=(1*22050:1:2*22050);
offset = exp(1i*w0*t);
shifted_sig = snd.*offset;
show_plot(shifted_sig, length(shifted_sig), fs, "Freqency Shifted signal");



% plotting function
function [] = show_plot(signal, l, Fs, title_txt)
    f = (-l/2:l/2-1)*(Fs/l);
    f_vals = fftshift(fft(signal)/l);
    
    plot(f, abs(f_vals));
    grid();
    xlabel("Frequency (Hz)");
    ylabel("Amplitude");
    xlim([-5000, 5000]);
    title(title_txt);
end 

