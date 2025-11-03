#include <stdio.h>
//#include "driver/spi_master.h"
#include "myUART.h"





void app_main(void)
{
    myUART_setup(115200);


    myUART_printf("hallo micro\r");



}