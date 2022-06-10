#pragma once
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"


void init_temperature_driver(void);

static inline float to_fahrenheit(float celsius);
float read_temperature(void);