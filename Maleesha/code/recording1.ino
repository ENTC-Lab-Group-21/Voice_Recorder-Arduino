#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>
#define SD_ChipSelectPin 10
#define buffsize 128
TMRpcm audio;
int audiofile = 0;
unsigned long i = 0;
bool recmode = 0;

void setup() {
 Serial.begin(9600);
  pinMode(A0, INPUT);
  //pinMode(2, INPUT_PULLUP);
  //attachInterrupt(0, button, LOW);
  SD.begin(SD_ChipSelectPin);
  audio.CSPin = SD_ChipSelectPin;
Serial.print("Start!!");
audio.startRecording("test.wav", 16000, A0); 
delay(3000);
audio.stopRecording("test.wav");
Serial.print("End!!!");
}

void loop() {
}

void button() {
  while (i < 300000) {
    i++;
  }
  i = 0;
  if (recmode == 0) {
    recmode = 1;
    audiofile++;
    switch (audiofile) {
      case 1: audio.startRecording("1.wav", 16000, A0); break;
      case 2: audio.startRecording("2.wav", 16000, A0); break;
      case 3: audio.startRecording("3.wav", 16000, A0); break;
      case 4: audio.startRecording("4.wav", 16000, A0); break;
      case 5: audio.startRecording("5.wav", 16000, A0); break;
      
    }
  }
  else {
    recmode = 0;
    switch (audiofile) {
      case 1: audio.stopRecording("1.wav"); break;
      case 2: audio.stopRecording("2.wav"); break;
      case 3: audio.stopRecording("3.wav"); break;
      case 4: audio.stopRecording("4.wav"); break;
      case 5: audio.stopRecording("5.wav"); break;
    }
  }
}
