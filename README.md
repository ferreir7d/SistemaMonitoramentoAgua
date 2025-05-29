# Sistema de Monitoramento do Nível de Água 💧

Projeto acadêmico desenvolvido por **Daniel Ferreira Bezerra** na Universidade Presbiteriana Mackenzie, sob orientação do professor André Luis de Oliveira.

## 📌 Descrição do Projeto

Este sistema realiza o monitoramento do nível de água em um reservatório utilizando um sensor ultrassônico e um microcontrolador Arduino. As leituras são exibidas em um display LCD e enviadas via protocolo MQTT através do módulo ESP8266. Quando o nível de água está abaixo do mínimo configurado, uma bomba de água é acionada automaticamente.

## 🚀 Como Reproduzir

1. Clone o repositório:
   ```bash
   git clone https://github.com/seu-usuario/sistema-monitoramento-nivel-agua.git
   ```

2. Abra o arquivo `codigo/sistema_nivel_agua.ino` na IDE do Arduino.

3. Faça o upload para um Arduino Uno com os periféricos conectados conforme descrito em `/documentacao/descricao_hardware.md`.

4. Acompanhe a simulação pelo display LCD e pelo Serial Monitor (MQTT simulado).

## 📂 Conteúdo do Repositório

- `/codigo`: Código-fonte do sistema (.ino)
- `/documentacao`: Documentação técnica (hardware, protocolos e comunicação)
- `/imagens`: Imagens de componentes e fluxogramas
- `README.md`: Instruções gerais

## 🧰 Hardware Utilizado

- Arduino Uno
- Sensor Ultrassônico HC-SR04
- Módulo ESP8266
- Display LCD 16x2 com I2C
- Bomba de água (simulada com LED)
- Fonte 5V independente
- Protoboard e jumpers


## 🌐 Comunicação via Internet (TCP/IP)

- Comunicação via Wi-Fi utilizando o **ESP8266**
- Protocolo de mensagens **MQTT**
- Pacotes JSON simulados no console Serial da Wokwi



## 📊 Interface e Fluxo de Dados

Fluxo:
1. Leitura com HC-SR04
2. Processamento no Arduino
3. Envio Serial (simulação MQTT)
4. Ação automática (ligar bomba)



## 📸 Imagens do Projeto

Veja na pasta `/imagens`.

## 📃 Licença

Projeto acadêmico – uso livre para fins educacionais.
