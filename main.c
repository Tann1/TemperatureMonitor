#include <stdio.h>

#include "drivers/temperature_ADC/include/temperature_ADC.h"
#include "drivers/LCD_I2C/include/LCD_I2C.h"
 
  int main() {
 
    init_temperature_driver();
    init_lcd();
    while(1) {
      sleep_ms(1000);
    }

    return -1; // since main should never return
}