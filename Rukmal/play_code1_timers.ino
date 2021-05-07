#include <avr/interrupt.h> // Use timer interrupt library
#include <SPI.h>
#include <SD.h>

//objects
File openedFile;//instance of opened file

//constant output pins
#define cs_pin 4
#define spek_pin 9

void setup() {

  Serial.begin(9600);//open the serial port
  Serial.println("Initializing the SD card ");
  if(!SD.begin(cs_pin)){
    Serial.println("Initialization Failed!");
    while(1);//Try again
  }
  Serial.println("Initializtion Done!");

  openedFile = SD.open("test1.wav",FILE_READ); //open the file
  openedFile.seek(44);
  
/****Set timer1 for 8-bit fast PWM output ****/
 pinMode(spek_pin, OUTPUT); // Make timer’s PWM pin an output
 TCCR1B = (1 << CS10); // Set prescaler 1 to get 65kHz PWM
 TCCR1A |= (1 << COM1A1); // Pin low when TCNT1=OCR1A
 TCCR1A |= (1 << WGM10); // Use 8-bit fast PWM mode
 TCCR1B |= (1 << WGM12);

/******** Set up timer2 to call ISR ********/
 cli();
 TCCR2A = (1<<WGM21); // CTC Mode
 TCCR2B = (1 << CS21); // Set prescaler to divide by 8
 TIMSK2 = (1 << OCIE2A); // Call ISR when TCNT2 = OCRA2
 OCR2A = 124; // set sample play rate to 8000Hz_124
 sei(); // Enable interrupts to generate waveform!
}

void loop() { // Nothing to do!
}

ISR(TIMER2_COMPA_vect) { // Called when TCNT2 == OCR2A
  if(openedFile.available()){
 OCR1AL = openedFile.read();
  }
  else{
    openedFile.close();
  }
}
