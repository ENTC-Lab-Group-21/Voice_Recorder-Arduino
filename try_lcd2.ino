#include <LiquidCrystal.h>

#include <Keypad.h>
const byte ROWS=4;
const byte COLS=3;

//Array to represent keys on keypad
 char keyMap[ROWS][COLS] ={
 {'1','2','3'},
 {'4','5','6'},
 {'7','8','9'},
 {'*','0','#'},
};

int menu = 1;
byte rowPins[ROWS]={1,2,3,4};
byte colPins[COLS]={5,6,7};

Keypad myKeypad= Keypad(makeKeymap(keyMap),rowPins,colPins,4,3);


LiquidCrystal lcd (A0, A1, A2, A3, A4, A5); // pins of the LCD. (RS, E, D4, D5, D6, D7)

void updateMenu() {
  
  switch (menu) {
    case 0:
      menu = 4;
      break;
    case 1:
      lcd.clear();
      lcd.print(">Song1");
      lcd.setCursor(0, 1);
      lcd.print(" Song2");
      break;
    case 2:
      lcd.clear();
      lcd.print(" Song1");
      lcd.setCursor(0, 1);
      lcd.print(">Song2");
      break;
    case 3:
      lcd.clear();
      lcd.print(">Song3");
      lcd.setCursor(0, 1);
      lcd.print(" Song4");
      break;
    case 4:
      lcd.clear();
      lcd.print(" Song3");
      lcd.setCursor(0, 1);
      lcd.print(">Song4");
      break;
    case 5:
      menu = 1;
      break;
    case 6:
      lcd.clear();
  }
}
//playing songs menu
void action1() {
  lcd.clear();
  lcd.print(">Playing Song1");
  delay(1500);
}
void action2() {
  lcd.clear();
  lcd.print(">Playing Song2");
  delay(1500);
}
void action3() {
  lcd.clear();
  lcd.print(">Playing Song3");
  delay(1500);
}
void action4() {
  lcd.clear();
  lcd.print(">Playing Song4");
  delay(1500);
}


void executeAction() {//now playing menu
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
    case 4:
      action4();
      break;
  }}

  
void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);
lcd.print("Welcome");
delay(1500);
updateMenu();
}

void down(){//down key function
    menu++;
    updateMenu();
    delay(100);
}

void up(){//up key function
    menu--;
    updateMenu();
    delay(100);
}

void okay(){//okay key for 5
     executeAction();
    updateMenu();
    delay(100);; 
}



  


void loop() {
  // put your main code here, to run repeatedly:
char whichKey= myKeypad.getKey();

lcd.setCursor(0,0);


if(whichKey=='2'){
  up();
   
  
}
if(whichKey=='8'){
  down();
  
}
if(whichKey=='5'){
  okay();

//if(whichKey==''){
//    menu--;
//   updateMenu();
//   delay(100);
//} 
//if(whichKey=='#'){
//  
//    lcd.clear();
//    
//  

}
} 
