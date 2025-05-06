# 🌐 Nuvem Exercise – Comunicação com o servidor joystick_server (BitDogLab + Node.js)

Este projeto implementa o **lado embarcado** de um sistema IoT, utilizando a placa **BitDogLab (RP2040)** para capturar dados físicos (temperatura, joystick, botões e direção da rosa dos ventos) e enviá-los via **TCP/IP** para um servidor Node.js hospedado na nuvem, disponível no repositório complementar [joystick_server](https://github.com/EnzoMello/joystick_server).

---

## 🧠 Visão Geral

O sistema foi dividido em dois módulos:

| Módulo           | Repositório                                 | Função Principal                                  |
|------------------|---------------------------------------------|---------------------------------------------------|
| 🖥️ Servidor      | [joystick_server](https://github.com/EnzoMello/joystick_server) | Recebe, valida e exibe os dados enviados pela placa. |
| 📡 Embarcado (este) | [Nuvem_exercise](https://github.com/EnzoMello/Nuvem_exercise) | Envia os dados da BitDogLab via protocolo TCP/IP. |

---

## 🎯 Objetivo do Projeto

- Utilizar a placa BitDogLab para ler sensores e botões físicos.
- Montar uma requisição HTTP em C e enviá-la via TCP/IP.
- Conectar-se a um servidor Node.js (na nuvem com Railway).
- Testar, validar e exibir os dados no console do backend.

---

## 🔧 Componentes Enviados para o Servidor

Os dados são convertidos em um objeto JSON e enviados para o endpoint `/receiveData`:

```json
{
  "temperatura": 27.3,
  "joystick": {
    "x": 410,
    "y": 825
  },
  "direcao": "Norte",
  "botoes": {
    "A": true,
    "B": false
  }
}
