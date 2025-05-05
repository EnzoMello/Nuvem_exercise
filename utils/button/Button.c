#include "Button.h"

void init_buttons() {
    gpio_init(BUTTON_A_PIN);
    gpio_set_dir(BUTTON_A_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_A_PIN);

    gpio_init(BUTTON_B_PIN);
    gpio_set_dir(BUTTON_B_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_B_PIN);
}

bool is_button_a_pressed() {
    return gpio_get(BUTTON_A_PIN) == 0;  // 0 = pressionado
}

bool is_button_b_pressed() {
    return gpio_get(BUTTON_B_PIN) == 0;
}
