# 💧 Sistema de Monitoramento do Nível de Água

**Projeto acadêmico desenvolvido por Daniel Ferreira Bezerra**  
**Universidade Presbiteriana Mackenzie**  
**Orientação: Prof. André Luis de Oliveira**

---

## 📌 Descrição do Projeto

Este projeto propõe o desenvolvimento de um sistema embarcado para **monitoramento automatizado do nível de água** em reservatórios. Utiliza um sensor ultrassônico HC-SR04 e um microcontrolador **Arduino Uno**, em conjunto com um módulo **ESP8266** para envio remoto dos dados via protocolo **MQTT**.

O nível de água é exibido em tempo real em um display LCD 16x2 com interface I2C, e as leituras são transmitidas por Wi-Fi em formato JSON simulado. Caso o nível detectado fique abaixo de um limite mínimo, o sistema aciona automaticamente uma bomba de água (simulada por um LED) como resposta preventiva.

---

## 🚀 Como Executar

1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/sistema-monitoramento-nivel-agua.git


2. Abra o arquivo `codigo/sistema_nivel_agua.ino` na IDE do Arduino.

3. Faça o upload para um Arduino Uno com os periféricos conectados conforme descrito em `/documentacao/descricao_hardware.md`.

4. Acompanhe a simulação pelo display LCD e pelo Serial Monitor (MQTT simulado).

## 📂 Conteúdo do Repositório

- `/codigo`: Código-fonte do sistema (.ino)
- `/documentacao`: Documentação técnica (hardware, protocolos e comunicação)
- `/imagens`: Imagens de componentes e fluxogramas
- `README.md`: Instruções gerais

## 🧰 Hardware Utilizado

Arduino Uno

Sensor Ultrassônico HC-SR04

Módulo Wi-Fi ESP8266

Display LCD 16x2 com interface I2C

Bomba d'água (simulada por LED)

Fonte de alimentação 5V independente

Protoboard e jumpers


## 🌐 Comunicação via Internet (TCP/IP)

Conectividade via Wi-Fi (ESP8266)

Protocolo de mensagens: MQTT (utilizando broker.hivemq.com)

Publicação e subscrição em tópicos específicos

Mensagens em formato JSON (simulação no console Serial da Wokwi)



## 📊 Interface e Fluxo de Dados

Medição do nível com o HC-SR04

Processamento no Arduino Uno

Exibição no LCD I2C

Envio via MQTT para broker público

Ação automática com base no nível (acionamento de bomba)

Controle remoto adicional de LEDs via MQTT

## 📃 Licença

Projeto acadêmico – uso livre para fins educacionais.
