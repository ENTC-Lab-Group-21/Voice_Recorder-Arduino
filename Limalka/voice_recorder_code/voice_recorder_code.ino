#include <SPI.h>
#include <SD.h>
#include <TMRpcm.h>
#define SD_ChipSelectPin 49

File myFile;
TMRpcm tmrpcm;
//TMRpcm audio;

void setup()
{
  //TCCR2B = TCCR2B & B11111000 | B00000001;  // for PWM frequency of 31372.55 Hz
  
  tmrpcm.speakerPin = 5;
  pinMode(A0, INPUT); // pin for mic input
  // The audio library needs to know which CS pin to use for recording
  tmrpcm.CSPin = SD_ChipSelectPin;
  
  // Open serial communications and wait for port to open
  Serial.begin(9600);
  while (!Serial){;}
  //checking for SD
  if (!SD.begin(SD_ChipSelectPin)) 
  {
    Serial.println("SD fail!!");
    return;
  }
  //char f[4] = "1.wav";
  /*----------- Main code -----------*/
 fileList();
 //record("record_test1.wav",3000);
 //fileList();
 
 //tmrpcm.startRecording(f,16000,A0);
 
 tmrpcm.setVolume(5);
 //tmrpcm.play("1-32kHz.wav");
 //tmrpcm.play("record_test1.wav");
 tmrpcm.play("1.wav");

 /*-------------- End --------------*/
  Serial.println();
  Serial.print("End!!! :)");
}
void loop()
{
  
}

//record and save wav file
//void record(String fileName, int t)
//{
//  Serial.println("Recording...");
//  tmrpcm.startRecording(fileName, 16000, A0); 
//  delay(t);
//  tmrpcm.stopRecording(fileName);
//  Serial.println("Recording Stopped!!!");
//}

//delete a file
void deleteFile(String fileName)
{
   Serial.print("Removing ");
   Serial.print(fileName);
   Serial.println("...");
  //checking for the file..
  if (SD.exists(fileName)) 
  {
    SD.remove(fileName);
    Serial.print(fileName);
    Serial.println(" Removed!!");
  } 
  else 
    Serial.println("file doesn't exist.");

}

//read a file
void readFile(String fileName)
{
  myFile = SD.open(fileName);
  if (myFile) 
  {
    Serial.print(fileName);
    Serial.println(" :");
    while (myFile.available()) 
    {
      Serial.write(myFile.read());
    }
    myFile.close();
    
  }
  else 
  {
    Serial.println("error opening test.txt");
  }
}

//print File List
void fileList()
{
  Serial.println();
  Serial.println("Files in SD card :");
  Serial.println();
  printDirectory(SD.open("/"), 0);
  Serial.println();
}

//creating a file
void createFile(String fileName)
{
  Serial.println("Creating a file...");
  myFile = SD.open(fileName, FILE_WRITE);
  myFile.close();
  Serial.print(fileName);
  Serial.println(" file created!!");
}

//writing in a file
void writeLine(String fileName, String text)
{
   myFile = SD.open(fileName, FILE_WRITE);
  if (myFile) 
  {
    Serial.print("Writing to ");
    Serial.println(fileName);
    myFile.println(text);
    myFile.close();
    Serial.println("done!!");
  } 
  else 
  {
    Serial.print("error opening ");
    Serial.print(fileName);
  }
  
}

void printDirectory(File dir, int numTabs) {
  while (true) 
  {
    File entry =  dir.openNextFile();
    if (! entry) 
      break;
    for (uint8_t i = 0; i < numTabs; i++) 
    {
      Serial.print("  ");
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) 
    {
      Serial.print("/");
      printDirectory(entry, numTabs + 1);
    } 
    else 
    {
      Serial.print("------> ");
      Serial.print(entry.size(), DEC);
      Serial.println("bytes");
    }
    entry.close();
  }
}
