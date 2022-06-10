cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(temperature_monitor C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_subdirectory(drivers)

add_executable(main main.c)
target_link_libraries(main PRIVATE temperature_ADC)


pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 1)
pico_add_extra_outputs(main)