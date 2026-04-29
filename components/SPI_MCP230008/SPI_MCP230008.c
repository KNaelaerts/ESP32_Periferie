#include <stdio.h>
#include "SPI_MCP230008.h"
#include "driver/spi_master.h"

spi_device_handle_t handle;

void MCP_setup(int spi_start)
{
    if(spi_start)
    {
    
        spi_bus_config_t myconfig =
        {
            .sclk_io_num = MCP_SCK,
            .mosi_io_num = MCP_MOSI,
            .miso_io_num = MCP_MISO,
            .quadhd_io_num = -1,
            .quadwp_io_num = -1,


        };
        spi_bus_initialize(SPI_HOST, &myconfig, SPI_DMA_CH_AUTO);

    }    
    spi_device_interface_config_t mydefConfig =
    {
        .mode =3,
        .clock_speed_hz =1 *1000*1000,
        .spics_io_num = MCP_SS,
        .queue_size = 2, 
    };
    spi_bus_add_device(SPI_HOST , &mydefConfig , &handle);


}
void MCP_write(mcp_reg_t wie, char hoeveel)
{
    char rx_bufje[3];
    char tx_bufje[3] = {
        (MCP_ADR << 1) | 0,
        wie,
        hoeveel
    };

    spi_transaction_t zenden=
    {
        .rx_buffer = rx_bufje,
        .tx_buffer = tx_bufje,
        .length = 3*8               //hier ging ik de eerste keer de mist in, je moet het per bit ingeven
        
    };


    spi_device_transmit(handle,&zenden);

}
char MCP_read(mcp_reg_t wie)
{
    //deze functie zou moeten kloppen maar heb ik niet getest
    char rx_bufje[3];
    char tx_bufje[3] = {
        (MCP_ADR << 1) | 1,
        wie,
        0x00
    };

    spi_transaction_t zenden=
    {
        .rx_buffer = rx_bufje,
        .tx_buffer = tx_bufje,
        .length = 3*8               
    };


    spi_device_transmit(handle,&zenden);
    return rx_bufje[2];

}



