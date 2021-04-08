#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

void setup()
{
  tmrpcm.speakerPin = 9;
  Serial.begin(9600);
  Serial.println("Start!!");
  if (!SD.begin(SD_ChipSelectPin)) 
  {
    Serial.println("SD fail-doc");
    return;
  }

  tmrpcm.setVolume(3);
  tmrpcm.play("1.wav");
  Serial.println("END!!");
}

void loop()
{
  
}
