#include <stdio.h>
#include "pico/stdlib.h"
#include "joystick.h"
#include "Button.h"
#include "tmp.h"
#include "wifi.h"
#include "serverConnect.h"

#include "pico/cyw43_arch.h" // Controla o módulo Wi-Fi CYW43439 da Raspberry Pi Pico W
#include "lwip/tcp.h" // Gerencia conexões TCP/IP (usado para enviar temperatura para o backend)
#include "lwip/dhcp.h"
#include "lwip/pbuf.h" // Manipula buffers de pacotes de rede (auxilia na transmissão e recepção de dados)


void setup_init() {
    stdio_init_all();

    init_wifi();

    // INICA JOYSTICK
    init_joystick();

    // INICIA BOTÃO
    init_buttons();

    // INICIAR TMP
    tmp_init();
}

int main()
{

    setup_init();

    while (true) {
        const char* direction = joystick_direction(read_joystick_x(), read_joystick_y(), 10);
        printf("Direction: %s\n", direction);

        float temperature = get_temp();
        printf("Temperature: %.2f\n", temperature);

        int x = read_joystick_x();
        int y = read_joystick_y();
        
        bool buttonA = !gpio_get(BUTTON_A_PIN);
        bool buttonB = !gpio_get(BUTTON_B_PIN);

        create_request(temperature, x, y, direction, buttonA, buttonB);


        sleep_ms(1500);
    }
}
