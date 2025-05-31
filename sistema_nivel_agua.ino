#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST"; 
const char* password = "";
const char* mqttServer = "broker.emqx.io";
const int mqttPort = 1883; 
const char* topic = "esp32/nivel_agua"; 

WiFiClient espClient;
PubSubClient client(espClient);

// Configuração do sensor de nível de água (HC-SR04)
#define TRIGGER_PIN 5
#define ECHO_PIN 18

void reconnectMQTT() {
    while (!client.connected()) {
        Serial.print("Tentando conectar ao MQTT...");
        if (client.connect("ESP32Client")) {
            Serial.println("Conectado ao MQTT!");
        } else {
            Serial.print("Falha na conexão. Código: ");
            Serial.println(client.state());
            delay(2000);
        }
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    // Conectar ao Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Tentando conectar ao Wi-Fi...");
    }
    Serial.println("Wi-Fi conectado.");

    // Configurar MQTT
    client.setServer(mqttServer, mqttPort);
    reconnectMQTT();
}

void loop() {
    if (!client.connected()) {
        reconnectMQTT();
    }
    client.loop();

    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    float level_cm = duration * 0.034 / 2; 

    // Publicar no MQTT
    String msg = String(level_cm);
    client.publish(topic, msg.c_str());
     
    // Enviar ao painel do Wokwi (formato JSON)
    Serial.print("{\"Nível de Água\": ");
    Serial.print(level_cm);
    Serial.println("}");

    delay(5000);
}	
