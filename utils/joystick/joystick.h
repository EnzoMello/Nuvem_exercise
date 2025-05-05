#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

// DEFINIR PINAGEM DO JOYSTICK
#define JOYSTICK_VRX 27
#define JOYSTICK_VRY 26

// DEFINIR VALORES MAX E MIN
#define JOYSTICK_MAX_VALUE 99
#define JOYSTICK_MIN_VALUE 0


void init_joystick();

int read_joystick_x();

int read_joystick_y();

const char* joystick_direction(uint8_t _x, uint8_t _y, uint8_t _dead_zone);

#endif