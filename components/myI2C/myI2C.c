#include <stdio.h>
#include "myI2C.h"
#include "driver/i2c_master.h"
#include "driver/i2c_types.h"

i2c_master_bus_handle_t bus_handle;
i2c_master_dev_handle_t mcp_handvat;

void myI2C_setup(void)
{
    i2c_master_bus_config_t i2c_mst_config = {
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .i2c_port = 0,
        .scl_io_num = 39,
        .sda_io_num = 42,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true,
    };


    i2c_device_config_t mcp_cfg = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = 0b0100000,
        .scl_speed_hz = 100000,
    };

        
    i2c_new_master_bus(&i2c_mst_config, &bus_handle);                   //I2C
    i2c_master_bus_add_device(bus_handle, &mcp_cfg, &mcp_handvat);      //ZORG VOOR SLAVE

}
void myI2C_write(char inwendig_adr, char waarde)
{
    char buffer[2] = {inwendig_adr, waarde};
    i2c_master_transmit(mcp_handvat, (uint8_t *)buffer, 2, 100);
    

}
char myI2C_read(char inwendige_adr)
{
    char buf_out[1];
    char buf_in[1];
    buf_out[0] = inwendige_adr;

    i2c_master_transmit_receive(mcp_handvat, (uint8_t *)buf_out,1,(uint8_t *)buf_in,1, 100);

    return *buf_in;
}
