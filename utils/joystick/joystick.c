#include "joystick.h"

// FUNÇÃO PARA INICIALIZAR O JOYSTICK
void init_joystick() {
    adc_init();
    adc_gpio_init(JOYSTICK_VRX);
    adc_gpio_init(JOYSTICK_VRY);
}

// FUNÇÃO PARA LER O EIXO X
int read_joystick_x() {
    adc_select_input(1);

    return adc_read() * 100 / 4095;
}

// FUNÇÃO PARA LER O EIXO Y
int read_joystick_y() {
    adc_select_input(0);

    return adc_read() * 100 / 4095;
}

// FUNÇÃO QUE SIMULA ROSA DOS VENTOS PARA A POSIÇÃO DO JOYSTICK
const char* joystick_direction(uint8_t x, uint8_t y, uint8_t dead_zone) {
    int dx = 0, dy = 0;

    if (x > (50 + dead_zone)) dx = 1;
    else if (x < (50 - dead_zone)) dx = -1;

    if (y > (50 + dead_zone)) dy = 1;
    else if (y < (50 - dead_zone)) dy = -1;

    // Mapeia (dx, dy) para direções
    const char* directions[3][3] = {
        {"Sudoeste", "Oeste", "Noroeste"},
        {"Sul",      "Centro", "Norte"},
        {"Sudeste", "Leste",  "Nordeste"}
    };

    return directions[dx + 1][dy + 1];  
}

