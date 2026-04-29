#include <stdio.h>
//#include "driver/spi_master.h"
#include "myUART.h"
#include "freertos/FreeRTOS.h"
#include "freertos/FreeRTOSConfig.h"
#include "I2C_MCP230008.h"






void app_main(void)
{
    myUART_setup(115200);


    myUART_printf("hallo micro\r");



}