# Documentação da Comunicação via Internet e Protocolo MQTT

## 1. Comunicação

- Utiliza o módulo ESP8266 para conexão Wi-Fi
- Comunicação via protocolo TCP/IP
- Pacotes enviados simulam dados no padrão JSON

## 2. Protocolo MQTT

- Cliente: ESP8266
- Broker: Mosquitto (simulado via Serial na Wokwi)
- Tópico publicado: `nivel/agua`
- Mensagem exemplo:
```json
{
  "nivel_agua_cm": 18,
  "data": "2025-05-28 15:42:00"
}
```

## 3. Simulação

- Como a Wokwi não permite envio real de pacotes MQTT, foi realizada uma simulação via `Serial.println()`, exibindo os dados no formato JSON, conforme se fossem publicados em um broker.

## 4. Possível expansão real

- Substituir o Serial pela biblioteca PubSubClient com autenticação
- Configurar broker MQTT local ou na nuvem (ex: HiveMQ, Mosquitto ou AWS IoT Core)
