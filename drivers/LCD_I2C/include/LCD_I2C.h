#pragma once
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"


#include "LCD_I2C_def.h"

#define I2C_SPEED (100 * 1000)


bool init_lcd(void); // return true if initialized properly else false
void write_byte(uint8_t byte, uint8_t type_of_register);
static inline void lcd_send_char(char character);
static inline void lcd_clear_screen(void);



