#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ====== Configurações WiFi ======
const char* ssid = "//";
const char* password = "//";

// ====== Broker MQTT ======
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;

// ====== Tópicos MQTT ======
const char* topic_sensor_global = "sensor/nivelagua";
const char* topic_led_vermelho  = "controle/led/vermelho";
const char* topic_led_azul  = "controle/led/azul";
const char* topic_sensor_local = "sensor/nivelagua/23";

// ====== Pinos HC-SR04 ======
const int trigPin = D6;
const int echoPin = D7;

// ====== LEDs e Buzzer ======
const int ledVerde = D4;
const int ledAmarelo = D3;
const int ledVermelho = D5;
const int buzzerPin = D8;

// ====== LCD I2C ======
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ====== Altura máxima do reservatório (em cm) ======
const float alturaTotal = 73.0;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);

  // Inicialização dos pinos
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Desliga tudo inicialmente
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(buzzerPin, LOW);

  // LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Conectando WiFi");

  setup_wifi();

  // MQTT
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  if (String(topic) == topic_led_vermelho) {
  // controle LED vermelho
} else if (String(topic) == topic_led_azul) {
  // controle LED azul
}
}

void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  lcd.clear();
  lcd.print("WiFi Conectado");
  delay(1000);
}

void callback(char* topic, byte* payload, unsigned int length) {
  String msg;
  for (unsigned int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }
  Serial.print("MQTT Msg: ");
  Serial.println(msg);

  // Controle dos LEDs via MQTT
  if (String(topic) == topic_led) {
    msg.toUpperCase();
    if (msg == "ON") {
      digitalWrite(ledVerde, HIGH);
      digitalWrite(buzzerPin, HIGH);
    } else if (msg == "OFF") {
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVermelho, LOW);
      digitalWrite(buzzerPin, LOW);
    } else if (msg == "VERDE") {
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVermelho, LOW);
    } else if (msg == "AMARELO") {
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarelo, HIGH);
      digitalWrite(ledVermelho, LOW);
    } else if (msg == "VERMELHO") {
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVermelho, HIGH);
    }
  }
}

long readUltrasonicDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2; // cm
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando MQTT...");
    if (client.connect("ESP8266Client")) {
      Serial.println("Conectado");
      client.subscribe(topic_led);
      client.subscribe(topic_sensor_global);
      client.subscribe(topic_led_vermelho);
      client.subscribe(topic_sensor_local);
      client.subscribe(topic_led_azul);
    } else {
      Serial.print("Falha rc=");
      Serial.print(client.state());
      Serial.println(" tentando em 5s");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long distancia = readUltrasonicDistance();
  float nivelAgua = alturaTotal - distancia;
  if (nivelAgua < 0) nivelAgua = 0; // segurança

  // Publica o nível via MQTT
  char msg[16];
  dtostrf(nivelAgua, 6, 2, msg); // float → string
  client.publish(topic_sensor_global, msg);
  client.publish(topic_led_vermelho, msg);
  client.publish(topic_sensor_local, msg);
  client.publish(topic_led_azul, msg);

  // Exibe no serial
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.print(" cm | Nível: ");
  Serial.print(nivelAgua);
  Serial.println(" cm");

  // Atualiza LCD (sem flicker)
  lcd.setCursor(0, 0);
  lcd.print("Nivel Agua:     ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(nivelAgua, 1);
  lcd.print(" cm");

  // Alerta automático por nível
  if (nivelAgua > 50) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzerPin, LOW);
  } else if (nivelAgua > 20) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(buzzerPin, LOW);
  } else {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(buzzerPin, HIGH);
  }

  delay(2000); // Leitura a cada 2s
}
