
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include<Servo.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,16,2);
int trigpin =A0;
int echopin =A1;
int distance;

float duration;
Servo myservo;
char customKey;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

;

void setup()
{
  
  lcd.begin();
  

  
  lcd.backlight();
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  
  Serial.begin(9600);
  myservo.attach(11);
  

  
  
}

void loop()
{
  
  
  distances();
  
  if(distance<=70){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("     welcome");
     lcd.setCursor(0, 1);
     lcd.print("Findbooks Easily");
     
     
    
  }
  else{
    lcd.clear();
    
  }
  controlmotor();
  
}
void distances(){

digitalWrite(trigpin,LOW);
delay(2);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);
duration = pulseIn(echopin,HIGH);
distance = (duration*0.034)/2;
//Serial.print(" The Distance is = ");
//Serial.print(distance);
//Serial.println("cm");
delay(500);
  
}
void controlmotor(){
  customKey = customKeypad.getKey();
  
if (customKey=='A') {
  
  myservo.write(0);
  delay(15);
   myservo.write(90);
   lcd.clear();
   lcd.setCursor(3, 1);
   lcd.print("You press A");
   
     delay(20);
   
    
   
  }
   if (customKey=='B') {
    
    myservo.write(0);
    delay(15);
    myservo.write(180);
    lcd.clear();
    lcd.setCursor(3, 1);
    lcd.print("You press B");
    //Serial.println("B");
    delay(20);
  }
   if (customKey=='C') {
    
    myservo.write(0);
    delay(15);
    lcd.clear();
    lcd.setCursor(3, 1);
    lcd.print("You press C");
    //Serial.println("C");
    delay(20);
  }
  
 

}
