void pitch_shift(){ // function for pitch shifting
  switch(pitch_factor){
    case 4 : ocr1a_val=250; break;
    case 3 : ocr1a_val=200; break;
    case 0 : ocr1a_val=170; break;
    case 1 : ocr1a_val=100; break;
    case 2 : ocr1a_val=75; break; 
  }
}

void start_play_pitch(String filename,byte factor){
 pitch_factor=factor;
 openfile(filename);
 pitch_shift();//take the pitch factor
 noInterrupts();// disable interupts
 TCCR1B = (1<<WGM12); // CTC Mode
 TCCR1B = (1 << CS11); // Set prescaler to divide by 8
 TIMSK1 = (1 << OCIE1A); // Call ISR when TCNT1 = OCRA1
 OCR1A = ocr1a_val; // set sample play rate to 8000Hz_124
 interrupts(); // Enable interrupts to generate waveform!
 
}

ISR(TIMER1_COMPA_vect) { // Called when TCNT1 == OCR1A
  if(data_file.available()){
    PORTA=data_file.read();//write data to PORTA
  }else{
  PORTA=0;
  
  Serial.println("OVER!");
  cli();
  }
    TCNT1 = 0;//set counter again to zero
}
