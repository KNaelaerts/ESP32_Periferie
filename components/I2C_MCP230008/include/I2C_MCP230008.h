#define I2C_HOST 1

#define MCP_ADR 0b0100000
#define MCP_SCL_pin 9
#define MCP_SDA_pin 8

typedef enum{
 IODIR =   0,   
 IPOL  =  1,
 GPINTEN = 2,
 DEFVAL = 3,
 INTCON = 4,
 IOCON  = 5,
 GPPU   = 6,
 INTF   = 7,
 INTCAP = 8,
 GPIO   = 9,
 OLAT   = 10,

}mcp_reg_t;

void MCP_setup(int i2c_start);
void MCP_write(mcp_reg_t wie, char hoeveel);
char MCP_read(mcp_reg_t wie);
