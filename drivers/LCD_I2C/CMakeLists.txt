add_library(LCD_I2C LCD_I2C.c include/LCD_I2C.h)
target_include_directories(LCD_I2C PUBLIC include/)
target_link_libraries(LCD_I2C PUBLIC pico_stdlib hardware_i2c)