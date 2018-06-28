  #include <SoftwareSerial.h>
int Tx = 5;
int Rx = 6;

SoftwareSerial mySerial(Tx,Rx);
void setup() {
  Serial.begin(9600);   // 시리얼 통신 시작
  mySerial.begin(9600);
}
 
void loop() {
  int soil = analogRead(A0);  // 아날로그 데이터를 soil로 저장
  Serial.println(soil);      // 아날로그값 시리얼로 출력
  delay(500);
  mySerial.println(soil);
} 
