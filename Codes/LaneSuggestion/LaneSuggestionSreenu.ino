#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int IRSensor1 = 10; // connect ir sensor to arduino pin 10
int IRSensor2 = 9; // connect ir sensor to arduino pin 9
int IRSensor3 = 8; // connect ir sensor to arduino pin 8
int IRSensor4 = A0; // connect ir sensor to arduino pinA0
int IRSensor5 = A1; // connect ir sensor to arduino pinA1
int IRSensor6 = A2; // connect ir sensor to arduino pinA2

void setup() {
 lcd.begin(16, 2); 
  pinMode(IRSensor1, INPUT); // sensor pin INPUT
  pinMode(IRSensor2, INPUT); // sensor pin INPUT
  pinMode(IRSensor3, INPUT); // sensor pin INPUT
  pinMode(IRSensor4, INPUT); // sensor pin INPUT
  pinMode(IRSensor5, INPUT); // sensor pin INPUT
  pinMode(IRSensor6, INPUT); // sensor pin INPUT

}

void loop() {
  int statusSensor1 = digitalRead (IRSensor1);
  int statusSensor2 = digitalRead (IRSensor2);
  int statusSensor3 = digitalRead (IRSensor3);
  int statusSensor4 = digitalRead (IRSensor4);
  int statusSensor5 = digitalRead (IRSensor5);
  int statusSensor6 = digitalRead (IRSensor6);

  if (statusSensor1 == LOW){
    lcd.setCursor(0,0);          
    lcd.print("Free Lane"); 
    lcd.setCursor(6,1);           
    lcd.print("  2  ");    
  }
 else if (statusSensor1 == LOW && statusSensor4 == LOW){
    lcd.setCursor(0,0);          
    lcd.print("Free Lane"); 
    lcd.setCursor(6,1);           
    lcd.print("  1  ");    
  
 }
 else if (statusSensor1 == LOW && statusSensor2 == LOW && statusSensor4 == LOW){
    lcd.setCursor(0,0);          
    lcd.print("Free Lane"); 
    lcd.setCursor(6,1);           
    lcd.print("  2  ");    
  
 }
 else if (statusSensor1 == LOW && statusSensor2 == LOW && statusSensor4 == LOW && statusSensor5 == LOW){
    lcd.setCursor(0,0);          
    lcd.print("Free Lane"); 
    lcd.setCursor(6,1);           
    lcd.print("  1  ");    
  
 }
 else if (statusSensor1 == LOW && statusSensor2 == LOW && statusSensor3 == LOW && statusSensor4 == LOW && statusSensor5 == LOW){
    lcd.setCursor(0,0);          
    lcd.print("Free Lane"); 
    lcd.setCursor(6,1);           
    lcd.print("  2  ");    
  
 }
 else if (statusSensor1 == LOW && statusSensor2 == LOW && statusSensor3 == LOW && statusSensor4 == LOW && statusSensor5 == LOW && statusSensor6 == LOW){
    lcd.setCursor(0,0);          
    lcd.print("Free Lane"); 
    lcd.setCursor(6,1);           
    lcd.print("  3  ");    
  
 }

}
