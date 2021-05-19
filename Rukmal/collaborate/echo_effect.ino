void start_play_echo(){
 noInterrupts();// disable interupts
 TCCR3B = (1<<WGM32); // CTC Mode
 TCCR3B = (1 << CS31); // Set prescaler to divide by 8
 TIMSK3 = (1 << OCIE3A); // Call ISR when TCNT3 = OCRA3
 OCR3A = 180; // set sample play rate to 8000Hz_124
 interrupts(); // Enable interrupts to generate waveform!
 
}

ISR(TIMER3_COMPA_vect) { // Called when TCNT3 == OCR3A
  if(i<2000 and status){
    var1 = data_file.read();
    PORTA = var1;
    delay_data[i] = var1;
    i++;
  }
  else if(i==2000){
    status=0;
    PORTA=delay_data[play_head];
    play_head++;
    if(play_head==1999){
      i=0;
      status=1;
    }
  }
    TCNT3 = 0;//set counter again to zero
}
