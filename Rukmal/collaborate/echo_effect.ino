
void start_play_echo(){
 noInterrupts();// disable interupts
 TCCR3B = (1<<WGM32); // CTC Mode
 TCCR3B = (1 << CS31); // Set prescaler to divide by 8
 TIMSK3 = (1 << OCIE3A); // Call ISR when TCNT3 = OCRA3
 OCR3A = 124; // set sample play rate to 8000Hz_124

 TCCR4B = (1<<WGM42); // CTC Mode
 TCCR4B = (1 << CS41); // Set prescaler to divide by 8
 TIMSK4 = (1 << OCIE4A); // Call ISR when TCNT3 = OCRA3
 OCR4A = 62; // set sample play rate to 8000Hz_124
 interrupts(); // Enable interrupts to generate waveform!
 
}

ISR(TIMER3_COMPA_vect) { // Called when TCNT3 == OCR3A
    var1=data_file.read();
    PORTA=var1;
    TCNT3 = 0;//set counter again to zero
}

ISR(TIMER4_COMPA_vect) { // Called when TCNT3 == OCR3A
    PORTA=var1/2;
    TCNT4 = 0;//set counter again to zero
}
