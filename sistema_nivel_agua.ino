#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define trigPin 6
#define echoPin 7

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Endereço I2C e tamanho do LCD

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // Aciona sensor ultrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  float tankHeight = 73.0;  // Altura do tanque em cm
  float waterLevel = tankHeight - distance;
  if (waterLevel < 0) waterLevel = 0;

  // Atualiza display LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nivel de Agua:");
  lcd.setCursor(0, 1);
  lcd.print(waterLevel);
  lcd.print(" cm");

  // Exibe no Serial console (simulando envio MQTT)
  Serial.print("Publishing to MQTT topic 'sensor/level': ");
  Serial.print("{\"nivel_agua\": ");
  Serial.print(waterLevel);
  Serial.println("}");

  delay(1000);
}

