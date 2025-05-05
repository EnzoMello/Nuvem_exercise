#ifndef WIFI_H
#define WIFI_H

#include "pico/stdlib.h"
#include <stdio.h>
#include "pico/cyw43_arch.h" // Controla o módulo Wi-Fi CYW43439 da Raspberry Pi Pico W
#define WIFI_SSID "Roteadorzin"
#define WIFI_PASSWORD "ENZOMELO1000"


void init_wifi();

#endif