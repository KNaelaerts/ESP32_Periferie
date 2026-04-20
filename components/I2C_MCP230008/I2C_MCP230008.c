#include <stdio.h>
#include "I2C_MCP230008.h"
#include "driver/i2c_master.h"



i2c_master_bus_config_t i2c_mst_config = {
    .clk_source = I2C_CLK_SRC_DEFAULT,
    .i2c_port = I2C_HOST,
    .scl_io_num = MCP_SCL_pin,
    .sda_io_num = MCP_SDA_pin,
    .glitch_ignore_cnt = 7,
    .flags.enable_internal_pullup = true,
};

i2c_master_bus_handle_t bus_handle;


i2c_device_config_t dev_cfg = {
    .dev_addr_length = I2C_ADDR_BIT_LEN_7,
    .device_address = MCP_ADR,
    .scl_speed_hz = 100000,
};

i2c_master_dev_handle_t dev_handle;



void MCP_setup(int i2c_start)
{
    //ik heb de i2c_new_master optioneel gemaakt voor als je die bus al hebt opstaan
    if(i2c_start) i2c_new_master_bus(&i2c_mst_config, &bus_handle); //zorg dat de i2c bus werkt
    
    ESP_ERROR_CHECK(i2c_master_bus_add_device(bus_handle, &dev_cfg, &dev_handle));    //voeg toestel toe


}
void MCP_write(mcp_reg_t wie, char hoeveel)
{
    uint8_t data_wr[2];
    data_wr[0] = wie;
    data_wr[1] = hoeveel;

    ESP_ERROR_CHECK(i2c_master_transmit(dev_handle, data_wr, 2, -1));

}


char MCP_read(mcp_reg_t wie)
{
    uint8_t buf[10];
    buf[0]= (uint8_t)wie;

    i2c_master_transmit_receive(dev_handle,buf,1,buf, 1,-1);

    return buf[0];
}