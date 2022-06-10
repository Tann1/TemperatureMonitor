#include "include/temperature_ADC.h"

void init_temperature_driver(void) {
    stdio_init_all();
    adc_init();
    adc_select_input(4); // on board temperature sensor
    adc_set_temp_sensor_enabled(true);
}

static inline float to_fahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

float read_temperature(void) {
    const float conversion_factor = 3.3 / (1 << 12);
    uint16_t result = adc_read();
   
    float voltage = result * conversion_factor;
     printf("read: %u voltage: %.2f\n", result, voltage); 
    float celsius = 27 - (voltage - 0.706) / 0.001721; // section 4.1.1 pico c sdk documentation 

    return to_fahrenheit(celsius);
}