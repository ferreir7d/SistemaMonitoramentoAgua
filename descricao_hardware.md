# Descrição do Hardware Utilizado

## 1. Placa de Desenvolvimento
- **Arduino Uno R3**
- Função: Processamento central das leituras e controle dos dispositivos.

## 2. Sensor
- **HC-SR04 – Sensor Ultrassônico**
- Usado para medir a distância da superfície da água.

## 3. Módulo de Comunicação
- **ESP8266 ESP-01**
- Responsável por conectar à rede Wi-Fi e enviar dados via protocolo MQTT.

## 4. Atuador
- **Bomba de água 5V**
- Acionada automaticamente quando o nível de água está abaixo do mínimo.

## 5. Exibição
- **Display LCD 16x2 com interface I2C**
- Mostra o nível de água em tempo real.

## 6. Alimentação
- Fonte 5V externa independente para evitar sobrecarga no Arduino.

## 7. Protótipo
- Conexões feitas em protoboard
- Simulação realizada na plataforma Wokwi.

## 8. Medidas e Encaixes (para impressão 3D futura)
- Sensor HC-SR04: 45mm x 20mm
- Caixa reservatório: dimensões livres no protótipo (não aplicável na simulação)
