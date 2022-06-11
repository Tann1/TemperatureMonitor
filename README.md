# TemperatureMonitor

## Intent
I noticed that we don't have a temperature monitor at home. Oftentimes, my mother and I debate about the the heater and whether it should be on or off. Our debates have no real substance as we can't quote direct temperature reading in our statements. Yes, I understand that there are ways around it such as just checking our phone or buying a temperature monitor but what fun would that be? Instead, I thought why not create one myself and then we can both have solid evidence concerning the temperature in the house. I saw an opportunity to apply my knowledge in embedded system to create something practical for my family. 

## Equipment
I plan on using raspberry pi's new and only microcontroller the raspberry pi pico. It uses the ARM microprocessor configured for low power consumption. One my main reasons for picking this microcontroller is it's low cost; they roughly sale for $4 each and it also has an onboard temperature sensor on one of its ADC peripheral. Though I will also need an LCD to display the value for which I will use a standard LCD, HD44780U, using an i2c connection. It'll be 4-bit transfer mode since with the upper 4 bits being RS, R/W, EN, gpio and lower 4-bits will be the 4 most significant bits followed by 4 least significant bits and EN to 1 which would complete the 8-bit transfer. In essence, we need 16 bits to send 8 bits of data information to the LCD through the I2C interface. Why use I2C? to have less wires. 

## Environment

- Using Windows 11 WSL2 with an Ubuntu instance
- VsCode
- CMake meta build system
- make build system
