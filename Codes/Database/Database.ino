#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
#include<LiquidCrystal.h>
#include <Servo.h>

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

char ssid[] = SECRET_SSID;   // your network SSID (name) 
char pass[] = SECRET_PASS;   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;

unsigned long myChannelNumber = 1358200;
const char * myWriteAPIKey = 3A8SM6QL7N97KXL5;

// Initialize our values
int large_vehicles = 0;
int small_vehicles = 0;
int Total_Amount = 0;
String myStatus = "";

void setup() 
{
  Serial.begin(115200);  // Initialize serial
  WiFi.mode(WIFI_STA); 
  ThingSpeak.begin(client);  // Initialize ThingSpeak

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
  
  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println("SECRET_SSID");
    while(WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }

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

    small_vehicles = small_vehicles + 1;
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

    small_vehicles = small_vehicles + 1;
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

    small_vehicles = small_vehicles + 1;
  }

  if (statusSensor1 == LOW && statusSensora == LOW)
  {
    large_vehicles = large_vehicles + 1;
  }

  if (statusSensor2 == LOW && statusSensorb == LOW)
  {
    large_vehicles = large_vehicles + 1;
  }

  if (statusSensor3 == LOW && statusSensorc == LOW)
  {
    large_vehicles = large_vehicles + 1;
  }

  // set the fields with the values
  ThingSpeak.setField(1, large_vehicles);
  ThingSpeak.setField(2, small_vehicles);
  Total_Amount = (30*large_vehicles)+(20*small_vehicles);
  ThingSpeak.setField(3, Total_Amount);

  // set the status
  ThingSpeak.setStatus(myStatus);
  
  // write to the ThingSpeak channel
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  delay(20000); // Wait 20 seconds to update the channel again
}
