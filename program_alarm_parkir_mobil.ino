/*** SYSTEM ALARM PARKIR MOBIL 
 *  ELECTRONICS TIPS & TRICK
 *  TINKERCAD SIMULATION
 */

 /***************************
ALARM PARKIR MOBIL
****************************/                     
#define TRIGPIN 6
#define ECHOPIN 7
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9,10,11,12,13);
int jarak,timer;
void setup(){
  lcd.begin(16, 2);
  lcd.print("   ALARM PARKIR");
  lcd.setCursor(0, 1);
  lcd.print("      MOBIL    ");
  delay(2000);
  lcd.clear();
  lcd.print("Status=");
  
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(5,OUTPUT);
}

void loop(){
  tone(5, 430, 150);
  delay(100);        
  digitalWrite(TRIGPIN, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);                  
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);                   
  timer = pulseIn(ECHOPIN, HIGH);        
  jarak= timer/58;                        
  if (jarak>200){
      lcd.setCursor(7,0);
      lcd.print("AMAN   ");
  }
  else if(jarak>150){
      lcd.setCursor(7,0);
      lcd.print("AWAS   ");
      digitalWrite(5,1);
      delay(500);
      digitalWrite(5,0);
      delay(500);
  }
  else if(jarak>100){
      lcd.setCursor(7,0);
      lcd.print("WASPADA");
      digitalWrite(5,1);
      delay(300);
      digitalWrite(5,0);
      delay(300);
  }
  else {
      lcd.setCursor(7,0);
      lcd.print("BAHAYA ");
      digitalWrite(5,1);
      delay(100);
      digitalWrite(5,0);
      delay(100);
  } 
}
