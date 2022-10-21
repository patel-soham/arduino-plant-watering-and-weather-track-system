#include<LiquidCrystal.h>
#include<dht.h>
dht DHT;
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  lcd.begin(16,2);
  pinMode(A0,INPUT);
  pinMode(8,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int chk=DHT.read11(8);
  int moist=analogRead(A0);
  lcd.setCursor(0,0);
  lcd.print("Humidity:");
  lcd.print(DHT.humidity);
  lcd.print((char)37);
  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  Serial.print("\n Moisture:");
  Serial.print(moist);
  if(moist<650)
    digitalWrite(13,LOW); 
  else
    digitalWrite(13,HIGH);
  delay(3000);
}
