#include<SoftwareSerial.h>
SoftwareSerial ss(4,5);
#include<dht.h>
#define pin 7
dht DHT;
int temp;
int hum; 

void setup() {
  Serial.begin(9600);
  ss.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);pinMode(6,OUTPUT);
}

void loop() {

  DHT.read11(7);
  int temp=DHT.temperature;
  int hum=DHT.humidity;
  Serial.print("Current humidity:");
  Serial.print(hum);
  Serial.print(" ");
  Serial.print("temperature:");
  Serial.print(temp);
  Serial.println("C  ");
  
  int ldr = analogRead(A0);
  int gas1 = analogRead(A1);
  int gas2 = analogRead(A2);

  Serial.print("GAS1:");
  Serial.println(gas1);
  Serial.print("Gas2:");
  Serial.println(gas2);
  Serial.print("ldr:");
  Serial.println(ldr);
  
  if(gas1 >800 || gas2 >850)
  {
    Serial.println("::::::::Gas detected:::::::");
    ss.print('A');
    digitalWrite(6,HIGH);
  }
  else if(ldr > 550)
  {
    Serial.println("::::::::brightness Low::::::");
    ss.print('B');
    digitalWrite(8,HIGH);
  }
  
  else if(hum <10)
  {
    Serial.println("::::::::Humidity value low:::::::");
    ss.print('C');
    digitalWrite(6,HIGH);
  }
  else if(temp>40)
  {
    Serial.println("::::::::Temperature High:::::::");
    ss.print('D');
    digitalWrite(9,HIGH);
    digitalWrite(6,HIGH);
  }
  else
  {
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(6,LOW);
  }
   delay(600);
}
