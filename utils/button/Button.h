#ifndef BUTTON_H
#define BUTTON_H

#include <stdio.h>
#include "pico/stdlib.h"

#define BUTTON_A_PIN 5
#define BUTTON_B_PIN 6

void init_buttons();  
bool is_button_a_pressed();  
bool is_button_b_pressed();

#endif
