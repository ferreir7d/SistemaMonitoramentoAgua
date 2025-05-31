# 💧 Sistema de Monitoramento do Nível de Água

**Projeto acadêmico desenvolvido por Daniel Ferreira Bezerra**  
**Universidade Presbiteriana Mackenzie**  
**Orientação: Prof. André Luis de Oliveira**

---

## 📌 Descrição do Projeto

Este projeto consiste em um sistema embarcado para monitoramento automatizado do nível de água em reservatórios. Ele utiliza um sensor ultrassônico HC-SR04 para medição e um ESP32 para processamento e comunicação via Wi-Fi, enviando os dados para um broker MQTT em tempo real.
O nível de água é exibido em um display LCD 16x2 com interface I2C, permitindo acompanhamento local. Caso o nível fique abaixo de um limite mínimo, o ESP32 aciona automaticamente uma bomba de água (simulada por um LED) para reabastecimento.
Além disso, o sistema possibilita monitoramento remoto via MQTT Explorer, garantindo acesso aos dados em tempo real.


---

## 🚀 Como Executar

1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/sistema-monitoramento-nivel-agua.git


- Abra o código na IDE do Arduino
- Arquivo: codigo/sistema_nivel_agua.ino
- Configure os parâmetros de Wi-Fi e MQTT no código-fonte
- Defina SSID e senha para conexão Wi-Fi
- Escolha um broker MQTT público, como broker.emqx.io
- Execute a simulação no Wokwi
- Certifique-se de que Internet (Simulated) está ativada
- Acompanhe a leitura dos dados no dashboard do Wokwi e no MQTT Explorer


## 📂 Conteúdo do Repositório

- /codigo - Código-fonte do sistema (.ino)
- /documentacao - Especificações técnicas e arquitetura do sistema
- /imagens - Diagramas do circuito e prints da simulação
- README.md - Instruções gerais

## 🧰 Hardware Utilizado

- ESP32 - Processamento e comunicação MQTT
- Sensor Ultrassônico HC-SR04 - Medição do nível de água
- Display LCD 16x2 com interface I2C - Exibição local das leituras
- Módulo Relé - Controle da bomba de água
- Bomba d'água (simulada por LED) - Representação do acionamento automático
- Fonte de alimentação 5V independente - Alimentação do sistema
- Protoboard e jumpers - Conexões do circuito



## 🌐 Comunicação via Internet (TCP/IP)

- Wi-Fi embutido no ESP32
- Protocolo MQTT para envio e recebimento de dados
- Broker MQTT público (broker.emqx.io) para comunicação dos sensores
- Publicação e subscrição em tópicos MQTT
- Mensagens JSON enviadas em tempo real para monitoramento remoto




## 📊 Interface e Fluxo de Dados

- Medição do nível de água com o HC-SR04
- Processamento dos dados pelo ESP32
- Exibição local no LCD I2C
- Envio MQTT para broker público
- Ação automática caso o nível esteja abaixo do mínimo (acionamento da bomba)
- Visualização remota via MQTT Explorer e painel do Wokwi IoT Dashboard


## 📃 Licença

Projeto acadêmico – uso livre para fins educacionais.
