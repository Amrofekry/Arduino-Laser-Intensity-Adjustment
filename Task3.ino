#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define laserPin 3
#define trigPin 8
#define echoPin 9
#define Buzzer 12

const float targetedIntensity = 0.4420970641;  // targeted Intensity in (microWatt/cm^2)
const float minDistance = 2.0;
const float maxDistance = 30.0;
const float soundSpeed = 344.5;  // Speed of sound in cm/s

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  pinMode(Buzzer, OUTPUT);
  pinMode(laserPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
  lcd.init();  
  lcd.backlight(); 
}

void loop() {
  float distance = calcDistance();
  Serial.print("Distance= ");
  Serial.println(distance);
  lcd.setCursor(0,0);
  lcd.print("Distance= ");
  lcd.print(distance);
  
  float power = calcPower(distance);
  Serial.print("Power= ");
  Serial.println(power);
  lcd.setCursor(0,1);
  lcd.print("Power= ");
  lcd.print(power);

  analogWrite(laserPin, round(power));

  // Simplify buzzer logic
  if(distance <= minDistance || distance >= maxDistance) {
    tone(Buzzer, 1000);  // Play a tone
    delay(50);
    noTone(Buzzer);      // Stop the tone
  }
  
  delay(200);
}

float calcDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  double duration = pulseIn(echoPin, HIGH);  // microseconds
  float distance = duration * (1e-4) * soundSpeed * 0.5;

  return distance;
}

float calcPower(float distance) {
  if (distance >= minDistance && distance <= maxDistance) {
    float power = targetedIntensity * 4 * PI * (distance * distance);  // power in microWatt
    return map(power, 0, 5000, 0, 255);  // Map power to PWM range
  } 
  return 0;  // Return 0 if out of range
}

