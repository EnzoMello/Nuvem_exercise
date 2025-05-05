#ifndef SERVERCONNECT_H
#define SERVERCONNECT_H

// inclusões de bibliotecas
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "lwip/tcp.h"
#include "lwip/ip_addr.h"
#include "lwip/init.h"
#include "lwip/netif.h"
#include "lwip/api.h"
#include "lwip/dns.h"

// definições de PROXY
#define SERVER_PORT 36308
#define PROXY_HOST "mainline.proxy.rlwy.net"

/*
* Função callback para tratar da resposta do servidor
*/
err_t tcp_client_recv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err);

/*
* Função que connecta ao servudor e envia um post de alerta
*/
void send_temp_to_server(const char *path, char *request_body, const char *type_method);

/*
* Função que cria um alerta para poder ser enviado ao servidor
*/
void create_request(float temperature, int joystick_x, int joystick_y, const char* direction, bool buttonA, bool buttonB);

#endif