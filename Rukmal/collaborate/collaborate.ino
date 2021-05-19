#include "Complex.h"
#include <SPI.h>
#include <SD.h>

File data_file;

//common
#define arrlength(ar) (sizeof(ar)/sizeof(ar[0])) //function to get the length of an array
#define cs_pin 49
#define pi 22.0/7
short samplerate=8000;

//pitch_shift
byte pitch_factor=0;
short ocr1a_val;

//frequency_shift
int whichsample = 1;
byte fshift =10;

//echo effect
char delay_data[2000];//create an array to stored delayed samples
char var1;
int i=0;
bool status=1;
short play_head=0;

 

void setup() {
  DDRA = 0xFF; //set PORTA as output
  Serial.begin(9600);//initializing 

  if(!SD.begin(cs_pin)){//Iniatializing SD card
    while(1);//Try again
  }
  Serial.println("Done!");
  
  start_play_pitch("10s_wav.wav",0);
  
  
  

}

void loop() {
  

}
