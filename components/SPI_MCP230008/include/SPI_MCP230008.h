#define SPI_HOST SPI2_HOST
//  let op SPI1_HOST (enum is dit 0) is vaak in gebruik voor het flash geheugen

//____chip___setup______________________________
#define MCP_ADR 0b0100000


//___SPI___setup_______________________________

#define MCP_SCK 12
#define MCP_MOSI 10
#define MCP_MISO 11
#define MCP_SS 13



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

void MCP_setup(int spi_start);
void MCP_write(mcp_reg_t wie, char hoeveel);
char MCP_read(mcp_reg_t wie);

//___dit is een eenvoudig voorbeeld voor een knipperlicht met 8 ledjes_____________________
/*
void app_main(void)
{
    MCP_setup(1);
    MCP_write(IODIR, 0b00000000);

    while(1)
    {
        vTaskDelay(100);
        MCP_write(GPIO , 0b00001111);

        vTaskDelay(100);
        MCP_write(GPIO , ~0b00001111);
    }
}

*/
