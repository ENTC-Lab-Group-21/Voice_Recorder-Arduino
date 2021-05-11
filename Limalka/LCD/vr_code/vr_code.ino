#include <Keypad.h>
#include <LiquidCrystal.h>

//keypad pins
byte colPins[3] = {22, 23, 24};
byte rowPins[4] = {25, 26, 27, 28};

// LCD pins
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//keypad initializing
char keys[4][3] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
/*
   1 - up button
   2- down button
   3 - ok button
*/

Keypad kpad = Keypad(makeKeymap(keys), rowPins , colPins , 4, 3);

//button pins
int upButton  = 30;
int selectButton  = 31;
int downButton  = 32;
int backButton = 33;

int menu = 1;
int subMenu = 0;

void setup()
{
  Serial.begin(9600);
  //button pins
  pinMode(upButton, INPUT_PULLUP );
  pinMode(downButton, INPUT_PULLUP );
  pinMode(selectButton, INPUT_PULLUP );
  pinMode(backButton, INPUT_PULLUP );

  // set up the LCD's number of columns and rows:
  lcd.begin (16, 4);

  // Welcome message and main menu
  lcd.setCursor(0, 1);
  lcd.print("   WELCOME!!!  ");
  delay(1000);
  lcd.clear();
  updateMenu();
}

void loop() {
  char key = kpad.getKey();
  if (key != NO_KEY)
  {
    lcd.print(key);
  }

  if (!digitalRead(downButton))
  {
    menu++;
    updateMenu();
    delay(100);
    while (!digitalRead(downButton));
  }
  if (!digitalRead(upButton))
  {
    menu--;
    updateMenu();
    delay(100);
    while (!digitalRead(upButton));
  }
  if (!digitalRead(selectButton))
  {
    Serial.println("Main Select Button");
    mainAction();
//    if (!subMenu) //checking for subMenu
//      mainAction();
//    else
//      subAction();
    updateMenu();
    subMenu = 0;
    delay(100);
    while (!digitalRead(selectButton));
  }
}
