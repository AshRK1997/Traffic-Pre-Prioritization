/*
Pin connections
(DO NOT GIVE DIRECT CONNECTIONS TO ARDUINO FROM LED USE THE RESISTORS)
red led1 = A0
green led1 = A1
red led1 = A2
green led1 = A3
red led1 = A4
green led1 = A5
ultrasonic vcc=5V
ultrasonic gnd = arduino gnd
ultrasonic1 trigger = 3
ultrasonic1 echo = 2
ultrasonic1 trigger = 4
ultrasonic1 echo = 5
ultrasonic1 trigger = 6
ultrasonic1 echo = 7
rfid VCC = 3.3V (WARNING: DO NOT CONNECT TO 5V)
rfid gnd= arduino gnd
rfid RST_PIN 9
rfid SDA 10
rfid SCK 13
rfid MOSI 11
rfid MISO 12
 

*/
#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
int a, b,c,i;
int l =0;
int m =0;
  int q = 0;
const int r1 = A0;
const int g1 = A1;
const int r2 = A2;
const int g2 = A3;
const int r3 = A4;
const int g3 = A5;
long duration;
int distance;
const int t1 = 3;
const int e1 = 2;
const int t2 = 4;
const int e2 = 5;
const int t3 = 6;
const int e3 = 7;

void setup() {
 pinMode(r1, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(g3, OUTPUT);
  pinMode(t1, OUTPUT);
  pinMode(t2, OUTPUT);
  pinMode(e1, INPUT);
  pinMode(e2, INPUT);
  pinMode(t3, OUTPUT);
  pinMode(e3, INPUT);
SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.begin(9600);


}

void loop() {
  
  a = ultra(t1,e1);
  
    if (a < 31){
     
  digitalWrite(r3, HIGH);
   digitalWrite(g3, LOW); 
  
   digitalWrite(g1, HIGH);
   digitalWrite(r1, LOW);  
digitalWrite(g2, LOW);
   digitalWrite(r2, HIGH); 
    for (i = 0;i<180;i++) {
    
    rfid();
    a = ultra(t1,e1);
    if (a > 30){
      break;
    }
   delay(1);
   }
  }
  else
  {
    digitalWrite(r3, HIGH);
   digitalWrite(g3, LOW); 
   digitalWrite(r1, HIGH);
   digitalWrite(g1, LOW);  
digitalWrite(g2, LOW);
   digitalWrite(r2, HIGH); 
rfid();
   }
   b = ultra(t2,e2);
    if (b < 31){
   digitalWrite(g1, LOW);
   digitalWrite(r1, HIGH); 
   
digitalWrite(g2, HIGH);
   digitalWrite(r2, LOW);  
   digitalWrite(r3, HIGH);
   digitalWrite(g3, LOW); 
    for (i = 0;i<180;i++) {
    
    rfid();
    b = ultra(t2,e2);
    if (b > 30){
      break;
    }
    delay(1);
   }
   }
   else
   {
    digitalWrite(r3, HIGH);
   digitalWrite(g3, LOW); 
   digitalWrite(r1, HIGH);
   digitalWrite(g1, LOW);  
digitalWrite(g2, LOW);
   digitalWrite(r2, HIGH); 
  rfid(); 
  }
   c = ultra(t3,e3);
    if (c < 31){
   digitalWrite(g2, LOW);
   digitalWrite(r2, HIGH);  
   digitalWrite(g3, HIGH);
   digitalWrite(r3, LOW); 
   digitalWrite(r1, HIGH);
   digitalWrite(g1, LOW);
   for (i = 0;i<180;i++) {
    rfid();
    c = ultra(t3,e3);
    if (c > 30){
      break;
    }
    delay(1);
   }
   }
   else
   {
   digitalWrite(r3, HIGH);
   digitalWrite(g3, LOW); 
   digitalWrite(r1, HIGH);
   digitalWrite(g1, LOW);  
   digitalWrite(g2, LOW);
   digitalWrite(r2, HIGH); 
    rfid(); 
   }
   
}
int ultra(int trigpin, int echopin){
digitalWrite(trigpin, LOW);
delayMicroseconds(2);


digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);


duration = pulseIn(echopin, HIGH);


distance= duration*0.034/2;
return distance;
}
int rfid(){
  int j;
 if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  
  String content= "";
  byte letter;
  for (byte j = 0; j < mfrc522.uid.size; j++) 
  {
     Serial.print(mfrc522.uid.uidByte[j] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[j], HEX);
     content.concat(String(mfrc522.uid.uidByte[j] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[j], HEX));
  }
  content.toUpperCase();
  Serial.println(content.substring(1));
  if (content.substring(1) == "B0 25 78 7A") 
  {
     digitalWrite(r3, HIGH);
   digitalWrite(g3, LOW); 
   digitalWrite(g1, HIGH);
   digitalWrite(r1, LOW);  
digitalWrite(g2, LOW);
   digitalWrite(r2, HIGH);
   delay(3000);
   Serial.println("in");
  }
  
}

