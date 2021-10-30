#include <LiquidCrystal.h>


LiquidCrystal led(2, 3, 4, 5, 6, 7);

int TMP36=A0, reading;
float voltage, suhu;
#define buzzer 8
#define lamp 9

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(lamp, OUTPUT);
  led.begin(16, 2);
  led.setCursor(0,0);
  led.print("Temperature:");
}

void loop()
{
  reading = analogRead(TMP36);
  voltage = (reading/1024.0) * 5.0;
  suhu = (voltage - 0.5)*100;
  
  led.setCursor(5,2);
  led.print(suhu);
  
  if (suhu > 50){
    tone(buzzer,15);
    digitalWrite(lamp, HIGH);
  }
  else
    noTone(buzzer);
    digitalWrite(lamp, LOW);
  
  delay(100);
}
