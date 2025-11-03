// de uart is aangemaakt voor uart2,
// maar hij gebruikt de zelfde pinnnen als uart0
// uart 0 wordt gebruikt als stdout dus pas hiermee op

// ook staat de snelheid van de esp-idf terminal op 115200
// andere snelheden zullen dus niet gezien worden


void myUART_setup(int baud);
void myUART_printf(const char *fmt, ...);

