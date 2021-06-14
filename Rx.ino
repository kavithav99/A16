#include<SoftwareSerial.h>
SoftwareSerial ss(4,5 );

void setup() {
  Serial.begin(9600);
  ss.begin(9600);
}

void loop() {

  char rcv;
  while(ss.available())
  {
    rcv = ss.read();
    Serial.println(rcv);
  if(rcv == 'A')
  {
    Serial.println("::::::::Gas detected:::::::");
    delay(700);
  }
  else if(rcv == 'B')
  {
    Serial.println("::::::::brightness Low::::::");
    delay(700);
  }
  else if(rcv == 'C')
  {
    Serial.println("::::::::Humidity value low:::::::");
    delay(700);
  }
  else if(rcv == 'D')
  {
    Serial.println("::::::::Temperature High:::::::");
    delay(700);
  }
 }
  rcv ="";
}
