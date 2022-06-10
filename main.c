#include <stdio.h>

#include "drivers/temperature_ADC/include/temperature_ADC.h"
 
  int main() {
 
    init_temperature_driver();
    while (1) {
    printf("%.2f Fahrenheit\n", read_temperature());
    sleep_ms(1000);
    }
}