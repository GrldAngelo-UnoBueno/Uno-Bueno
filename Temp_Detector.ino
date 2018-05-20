const int sensorPin = A0;
const int pinNumber = 6;
const float baselineTemp =35.0;
int notes[] = {4000,3000};
int switchState = 0;

//
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int temperaturePin = 0;


void setup()
{
  
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);
  pinMode(6,OUTPUT);
}


void loop()
{
  
  float degreesC, degreesF;

 float voltage;

  voltage = getVoltage(temperaturePin);
  
 
  degreesC = (voltage - 0.5) * 100.0;
  degreesF = degreesC * (9.0/5.0) + 32.0;
  
  lcd.setCursor(0, 0);   // Sets cursor to 0,0
  lcd.print("Temp:");// Prints "Temp:" to the LCD Display
  lcd.setCursor(5,1);// Sets the LCD cursor to AFTER the "Temp:"
  lcd.print("Celsius");
  lcd.setCursor(6, 0);
  lcd.print(degreesC);  // Change to "degreesC" for celsius
  delay(3000);          // 10 Second delay between refreshes.
  lcd.clear();        // Refreshes the temperature
   
 //////
 int sensorVal = analogRead(sensorPin);
 Serial.print("sensor Value: ");
  Serial.print(sensorVal); 

float voltage2 = (sensorVal/1024.0) * 5.0;

Serial.print(", Volts: ");
  Serial.print(voltage);

  Serial.print(", degrees C: "); 
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);

   if(temperature < baselineTemp){
    noTone(6);
  } // if the temperature rises + degrees, 
  else if(temperature >= baselineTemp+0.5 ){
  for(int thisPin =3; thisPin ++;){
  tone(6,notes[1]);
  delay(100);
  tone(6,notes[0]);
  delay(100);

  lcd.setCursor(3,0);
  lcd.print("Overheating");
  delay(1000);


  }
 
    
  }
 delay(500);
}


float getVoltage(int pin)
{
 
  return (analogRead(pin) * 0.004882814);
  
  
}


