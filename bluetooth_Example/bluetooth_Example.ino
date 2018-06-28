#include <SoftwareSerial.h>

int TxPin = 2;
int RxPin = 3;
int Button = 7;
int ledPin1 = 13;
int ledPin2 = 12;
int ledPin3 = 11;
SoftwareSerial BTSerial(TxPin, RxPin); 

void setup()  
{
  BTSerial.begin(9600);
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  pinMode(Button,INPUT);
  
}

void loop()
{
  if (digitalRead(Button) == LOW){
    while(digitalRead(Button) == LOW);
    BTSerial.println("a");
  }
  if (BTSerial.available())
  {
    char cmd = (char)BTSerial.read();
    if(cmd == '1') {
      digitalWrite(ledPin1,HIGH);
      digitalWrite(ledPin2,LOW);
      digitalWrite(ledPin3,LOW);
    } else if(cmd == '2') {
      digitalWrite(ledPin1,LOW);
      digitalWrite(ledPin2,HIGH);
      digitalWrite(ledPin3,LOW);
    } else if(cmd == '3') {
      digitalWrite(ledPin1,LOW);
      digitalWrite(ledPin2,LOW);
      digitalWrite(ledPin3,HIGH);
    } else if(cmd == '0') {
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      delay(200);
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      delay(200);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH);
      delay(200);
      digitalWrite(ledPin3, LOW);
      }
    }
}
