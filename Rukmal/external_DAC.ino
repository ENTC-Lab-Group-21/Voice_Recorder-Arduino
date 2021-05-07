#include <SPI.h>
#include <SD.h>


//objects
File data_file;//instance of opened file


//constant output pins
#define cs_pin 10


void setup() {
  DDRD = 0xFF;//set PORTD as OUTPUT

  if(!SD.begin(cs_pin)){//Iniatializing
    while(1);//Try again
  }
  data_file = SD.open("test2.wav",FILE_READ);

  char first = data_file.read();//check the first character
  if (first=="W"){
  data_file.seek(43);// go to the PCM data of wav file
  }else{
  data_file.seek(0);
  }

  
  adjust_pitch(0);



}

void loop() {
  

}

void adjust_pitch(int factor){
  
  int sample_rate = 8000 + 2000*(factor);
  
   /******** Set up timer2 to call ISR ********/
 cli();
 TCCR2A = (1<<WGM21); // CTC Mode
 TCCR2B = (1 << CS21); // Set prescaler to divide by 8
 TIMSK2 = (1 << OCIE2A); // Call ISR when TCNT2 = OCRA2
 OCR2A = (1000000/sample_rate)-1; // set sample play rate to 8000Hz_124
 sei(); // Enable interrupts to generate waveform!
  
  
}

ISR(TIMER2_COMPA_vect) { // Called when TCNT2 == OCR2A
  if(data_file.available()){
  PORTD = data_file.read();
  }
  else{
    data_file.close();
    cli();
  }
}
