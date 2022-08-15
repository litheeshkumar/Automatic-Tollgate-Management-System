#include<LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int IRSensor1 = 10; // connect ir sensor to arduino pin 10
int IRSensora = 9; // connect ir sensor to arduino pin 9
int IRSensor2 = 8; // connect ir sensor to arduino pin 8
int IRSensorb = A0; // connect ir sensor to arduino pin A0
int IRSensor3 = A1; // connect ir sensor to arduino pin A1
int IRSensorc = A2; // connect ir sensor to arduino pin A2

Servo myservo1;
int pos1 = 0;    // variable to store the servo position
Servo myservo2;
int pos2 = 0;    // variable to store the servo position
Servo myservo3;
int pos3 = 0;    // variable to store the servo position

void setup() 
{
  pinMode(IRSensor1, INPUT); // sensor pin INPUT
  pinMode(IRSensora, INPUT); // sensor pin INPUT
  pinMode(IRSensor2, INPUT); // sensor pin INPUT
  pinMode(IRSensorb, INPUT); // sensor pin INPUT
  pinMode(IRSensor3, INPUT); // sensor pin INPUT
  pinMode(IRSensorc, INPUT); // sensor pin INPUT
  
  myservo1.attach(7);  // attaches the servo on pin 7 to the servo object
  myservo2.attach(6);  // attaches the servo on pin 6 to the servo object
  myservo3.attach(5);  // attaches the servo on pin 5 to the servo object
}

void loop() 
{
  int statusSensor1 = digitalRead (IRSensor1);
  int statusSensora = digitalRead (IRSensora);
  int statusSensor2 = digitalRead (IRSensor2);
  int statusSensorb = digitalRead (IRSensorb);
  int statusSensor3 = digitalRead (IRSensor3);
  int statusSensorc = digitalRead (IRSensorc);
  
  if (statusSensor1 == LOW)
  {
    for (pos1 = 0; pos1 <= 90; pos1 += 1) // goes from 0 degrees to 180 degrees 
    { 
      myservo1.write(pos1);              // tell servo to go to position in variable 'pos1'
      delay(3000);                       // waits 3s for the servo to reach the position
    }
    
    for (pos1 = 90; pos1 >= 0; pos1 -= 1) // goes from 180 degrees to 0 degrees
    { 
      myservo1.write(pos1);              // tell servo to go to position in variable 'pos1'
      delay(3000);                       // waits 3s for the servo to reach the position
    }
  }

    if (statusSensor2 == LOW)
  {
    for (pos2 = 0; pos2 <= 90; pos2 += 1) // goes from 0 degrees to 180 degrees 
    { 
      myservo2.write(pos2);              // tell servo to go to position in variable 'pos2'
      delay(3000);                       // waits 3s for the servo to reach the position
    }
    
    for (pos2 = 90; pos2 >= 0; pos2 -= 1) // goes from 180 degrees to 0 degrees
    { 
      myservo2.write(pos2);              // tell servo to go to position in variable 'pos2'
      delay(3000);                       // waits 3s for the servo to reach the position
    }
  }

    if (statusSensor3 == LOW)
  {
    for (pos3 = 0; pos3 <= 90; pos3 += 1) // goes from 0 degrees to 180 degrees 
    { 
      myservo3.write(pos3);              // tell servo to go to position in variable 'pos3'
      delay(3000);                       // waits 3s for the servo to reach the position
    }
    
    for (pos3 = 90; pos3 >= 0; pos3 -= 1) // goes from 180 degrees to 0 degrees
    { 
      myservo3.write(pos3);              // tell servo to go to position in variable 'pos3'
      delay(3000);                       // waits 3s for the servo to reach the position
    }
  }
}
