#include "include/LCD_I2C.h"

// Utility functions
static bool init_i2c(uint32_t i2c_speed_in_khz) {
    i2c_init(i2c_default, i2c_speed_in_khz);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C); // gpio 4
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C); // gpio 5
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);

    uint8_t data_read; 
    return i2c_read_blocking(i2c_default, DEFAULT_SLAVE_ADDR, &data_read, 1, false) > 0;
}

// assuming data is already set up correctly
// upper 4 bits are data bits and lower 4 are RS[0], R/W[1], CS[2], Don't Care[3] 
static inline void  write_four_bits(uint8_t data) { 
    i2c_write_blocking(i2c_default, DEFAULT_SLAVE_ADDR, &data, 1, false);
}

static void toggle_enable(uint8_t data) {
    sleep_us(600);
    write_four_bits(data | ENABLE_BIT);
    sleep_us(600);
    write_four_bits(data & ~ENABLE_BIT);
    sleep_us(600);

}

// public functions

bool init_lcd(void) {
    bool i2c_properly_initialized = init_i2c(I2C_SPEED);
    lcd_clear_screen();
   
}
void write_byte(uint8_t byte, uint8_t type_of_register) { 
    uint8_t higher_data_bits = ((byte & 0xF0) | type_of_register) & ~ENABLE_BIT;
    uint8_t lower_data_bits = ((byte << 4) & 0xF0 | type_of_register) & ~ENABLE_BIT;
    
    toggle_enable(higher_data_bits); // 1800us ~ 1.8ms send DB7 to DB4
    toggle_enable(lower_data_bits);  // 1800us ~ 1.8ms send DB3 to DB0
                                     // 3.2ms minimum to write one byte 
}

static inline void lcd_send_char(char character) {
    write_byte(character, DATA_WRITE_REG);  
}

static inline void lcd_clear_screen(void) {
    write_byte(CLEAR_DISPLAY, COMMAND_REG);
}