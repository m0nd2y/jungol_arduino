#include <SoftwareSerial.h>
int Tx = 5;
int Rx = 6;
SoftwareSerial mySerial(Tx,Rx);
String myString="";

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    mySerial.begin(9600);
    pinMode(2,OUTPUT);
}

void loop() {
  //LED출력
  while(mySerial.available())  //mySerial 값이 있으면
  {
    char myChar = (char)mySerial.read();  //mySerial int형식의 값을 char형식으로 변환
    myString+=myChar;   //수신되는 문자열을 myString에 모두 붙임 (1바이트씩 전송되는 것을 모두 붙임)
    delay(5);           //수신 문자열 끊김 방지
  }
  
  if(!myString.equals(""))  //myString 값이 있다면
  {
    Serial.println("input value: "+myString); //시리얼모니터에 myString값 출력
 
      if(myString=="on")  //myString 값이 'on' 이라면
      {
        digitalWrite(2, HIGH); //LED ON
      } else {
        digitalWrite(2, LOW);  //LED OFF
      }
      
    myString="";  //myString 변수값 초기화
  }

  //토양 습도 센서
  int soil = analogRead(A0);  // 아날로그 데이터를 soil로 저장
  Serial.println(soil);      // 아날로그값 시리얼로 출력
  delay(500);
  mySerial.println(soil);
}
