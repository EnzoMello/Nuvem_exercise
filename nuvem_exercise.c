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

/**
 * @brief Função de inicialização do sistema.
 * 
 * Esta função realiza a inicialização de diversos módulos necessários para o funcionamento do sistema, 
 * incluindo a comunicação Wi-Fi, joystick, botões e sensor de temperatura.
 * 
 * @param None
 * @return None
 */
void setup_init() {
    stdio_init_all(); 

    init_wifi();  

    init_joystick(); 

    init_buttons();  

    tmp_init();  
}

/**
 * @brief Função principal do sistema.
 * 
 * Este é o loop principal onde o sistema coleta dados do joystick, dos botões e da temperatura, 
 * além de enviar os dados para o backend. O programa realiza a coleta de dados a cada 1500ms.
 * 
 * @param None
 * @return None
 */
int main()
{
    setup_init();  // Realiza a inicialização de todos os módulos necessários.

    while (true) {
        // Lê a direção do joystick com base nos eixos X e Y e a zona morta
        const char* direction = joystick_direction(read_joystick_x(), read_joystick_y(), 10);
        printf("Direction: %s\n", direction);  ///< Exibe a direção no terminal.

        // Lê a temperatura do sensor TMP
        float temperature = get_temp();
        printf("Temperature: %.2f\n", temperature);  ///< Exibe a temperatura no terminal.

        // Lê os valores dos eixos X e Y do joystick
        int x = read_joystick_x();
        int y = read_joystick_y();

        // Lê o estado do botão A e B
        bool buttonA = !gpio_get(BUTTON_A_PIN);  ///< Inverte o valor do botão A.
        bool buttonB = !gpio_get(BUTTON_B_PIN);  ///< Inverte o valor do botão B.

        // Envia os dados coletados (temperatura, eixos, direção, status dos botões) para o backend
        create_request(temperature, x, y, direction, buttonA, buttonB);

        sleep_ms(1500);  ///< Aguarda 1500ms antes de realizar a próxima leitura.
    }
}
