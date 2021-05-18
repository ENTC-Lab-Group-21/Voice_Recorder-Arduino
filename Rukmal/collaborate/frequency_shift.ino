//for frequency shifting

float expo(int sample_index){
  
  return cos(44.0*fshift*sample_index/(samplerate*7.0));
}

void start_play_freq(){
 whichsample=1;
 noInterrupts();// disable interupts
 TCCR0B = (1<<WGM02); // CTC Mode
 TCCR0B = (1 << CS01); // Set prescaler to divide by 8
 TIMSK0 = (1 << OCIE0A); // Call ISR when TCNT0 = OCRA0
 OCR0A = 180; // set sample play rate to 8000Hz_124
 interrupts(); // Enable interrupts to generate waveform!
 
}

ISR(TIMER0_COMPA_vect) { // Called when TCNT0 == OCR0A
    PORTA=int(data_file.read())*expo(whichsample);//write data to PORTA
    whichsample++;
    TCNT0 = 0;//set counter again to zero
}
