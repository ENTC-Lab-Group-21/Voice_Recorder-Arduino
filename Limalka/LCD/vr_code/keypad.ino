void updateMenu() {
  switch (menu) {
    case 0:
      menu = 3;
      lcd.clear();
      lcd.print("Record");
      lcd.setCursor(0, 1);
      lcd.print("Gallery");
      lcd.setCursor(0, 2);
      lcd.print("> About Device <");
      break;
    case 1:
      lcd.clear();
      lcd.print("> Record <");
      lcd.setCursor(0, 1);
      lcd.print("Gallery");
      lcd.setCursor(0, 2);
      lcd.print("About Device");

      break;
    case 2:
      lcd.clear();
      lcd.print("Record");
      lcd.setCursor(0, 1);
      lcd.print("> Gallery <");
      lcd.setCursor(0, 2);
      lcd.print("About Device");
      break;
    case 3:
      lcd.clear();
      lcd.print("Record");
      lcd.setCursor(0, 1);
      lcd.print("Gallery");
      lcd.setCursor(0, 2);
      lcd.print("> About Device <");
      break;
    case 4:
      menu = 1;
      lcd.clear();
      lcd.print("> Record <");
      lcd.setCursor(0, 1);
      lcd.print("Gallery");
      lcd.setCursor(0, 2);
      lcd.print("About Device");
      break;
  }
}

void recordAction() 
{
  lcd.clear();
  lcd.print("  RECORDING... ");
  lcd.setCursor(0, 2);
  lcd.print(" Press OK to ");
  lcd.setCursor(0, 3);
  lcd.print("    STOP    ");
  //start recording
  delay(300); // to stop jumping in to stop recording when pressed OK to record from the record sub menu
  while(digitalRead(selectButton));
  //stop recording
  lcd.clear();
  lcd.print("   RECORDING    ");
  lcd.setCursor(0, 1);
  lcd.print("    STOPPED!!   ");
  lcd.setCursor(0, 2);
  lcd.print(" Press BACK for ");
  lcd.setCursor(0, 3);
  lcd.print("   Main menu   ");
  while(digitalRead(backButton));;
}

void mainAction() 
{
  subMenu = menu;
  switch (menu) 
  {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
  }
}

void subAction() 
{
  switch (subMenu) 
  {
    case 1:
      recordAction();
      break;
    case 2:
      //action2();
      lcd.clear();
      lcd.print("sub Action 2 ");
      break;
    case 3:
      //action3();
      lcd.clear();
      lcd.print("sub Action 3");
      break;
  }
}

void action1() 
{
  lcd.clear();
  lcd.print("  > Record <  ");
  lcd.setCursor(0, 1);
  lcd.print(" Press OK to ");
  lcd.setCursor(0, 2);
  lcd.print("    start    ");
  delay(300); // stop jump in to recording when pressed OK to enter to the record sub menu
  while(1)
  {
    if (!digitalRead(selectButton))
    {
      recordAction();
      return;
    }
    else if (!digitalRead(backButton))
      return;
  }

}
void action2() 
{
  lcd.clear();
  lcd.print("  > Gallery < ");
  lcd.setCursor(0, 1);
  lcd.print("  ------------");
  while(digitalRead(backButton));
}
void action3() 
{
  lcd.clear();
  lcd.print("> About Device <");
  lcd.setCursor(0, 1);
  lcd.print(" Voice Recorder");
  lcd.setCursor(0, 2);
  lcd.print("      v1.0      ");
  lcd.setCursor(0, 3);
  lcd.print(" We are Group 21");
  while(digitalRead(backButton));
  //delay(1500);
}
