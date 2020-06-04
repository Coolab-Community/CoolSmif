# Coolsmif
STM32F7 - touchgfx & FreeRTOS project with UART, I2C_DMA (slave), LWIP and Modbus tcp/ip peripherals.

This project allow you to display on the main screen differents status with a scrollwheel and in secondary screen you can check the logs provided by an automate (RS232 protocol). The logs are parsed and send through I2C_DMA to a master (See CoolBox project with I2C).  

                               
                                               -------------------
                                               |                 |
                                               |                 |
                                               |                 |
                           VCOM(USART1) ------>| CN14        PB9 |--> I2C1_SDA
                                               |                 |
                                               |             PB8 |--> I2C1_SCL
                                               |                 |
                                               |                 |
                                               |                 |
                                               |                 |
                                               |                 |
                                               |                 |
                                               |                 |         
                                               |                 |
                                               |                 |
                                               |                 |
                                               | SMT32F746ZGT6   |--> Touchscreen (Two screens: screen1 status & screen2 = logs)
                                               |                 |
                                               -------------------

Software compatibility:
STM32CubeIDE ==> V1.2.1
STM32CubeMX ==> V5.6
TouchGFX ==> V4.13

To customize or modify the program open .cproject in STM32CubeIDE workspace. 
In linker setting don't forget to add gcc library path if different, by default gcc library path is "C:/TouchGFXProjects/CoolBox_CubeIDE_V1.1/Middlewares/ST/touchgfx/lib/core/cortex_m7/gcc"
