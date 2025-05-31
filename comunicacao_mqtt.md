# Documentação da Comunicação via Internet e Protocolo MQTT

## 1. Comunicação

- Utiliza o módulo ESP8266 para conexão Wi-Fi
- Comunicação via protocolo TCP/IP
- Pacotes enviados simulam dados no padrão JSON

## 2. Protocolo MQTT

- Cliente: ESP32
- Broker: Mosquitto (broker.emqx.io – MQTT real)
- Tópico publicado: nivel/agua
- Mensagem exemplo:

```json
{
  "nivel_agua_cm": 0.0,
  "data": "2025-05-28 22:30:00"
}
```

## 3. Simulação

- O Wokwi permite simulação de MQTT real, possibilitando testes diretos com um broker público
- Configuração do ESP32 para envio de dados via Wi-Fi
- Exibição das mensagens em tempo real no MQTT Explorer

## 4. Possível expansão real

- Melhoria na segurança: Adicionar autenticação MQTT via TLS
- Interface gráfica: Desenvolvimento de um dashboard web ou aplicativo móvel
- Armazenamento de histórico: Implementação de banco de dados para análise de tendências
- Notificações remotas: Envio de alertas via Telegram, e-mail ou integração com API externa

