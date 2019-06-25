#include "octane_machdep.h"

#include <dev/arcbios/arcbios.h>

int main(void);

int
main(void)
{
	arcbios_Restart();
	//octanerestart();
	return 0;
#if 0
	u_long io3c_base;

	io3c_base = PHYS_TO_XKPHYS((uint64_t)(IP30_BRIDGE_WIDGET) << 36, CCA_NC) +
				BRIDGE_PCI0_MEM_SPACE_BASE + 0x500000 + IOC3_UARTA_BASE;

#if 0
#define divrnd(n, q)    (((n)*2/(q)+1)/2)   /* divide and round off */
    int rate;
    rate = divrnd(((22000000 / 3) / 16), 9600);
#undef  divrnd

	*(volatile uint8_t *)(io3c_base + com_lcr) = LCR_DLAB;
	*(volatile uint8_t *)(io3c_base + com_dlbl) = rate;
	*(volatile uint8_t *)(io3c_base + com_dlbh) = rate >> 8;
	*(volatile uint8_t *)(io3c_base + com_lcr) = LCR_8BITS;
	*(volatile uint8_t *)(io3c_base + com_mcr) = MCR_DTR | MCR_RTS;
	*(volatile uint8_t *)(io3c_base + com_ier) = 0;
	*(volatile uint8_t *)(io3c_base + com_fifo) = FIFO_ENABLE | FIFO_RCV_RST | FIFO_XMT_RST | FIFO_TRIGGER_1;
#endif


	DELAY(2000);
	*(volatile uint8_t *)(io3c_base + com_data) = (0x0A & 0xff);
	DELAY(2000);
	DELAY(2000);
	*(volatile uint8_t *)(io3c_base + com_data) = (u_int8_t)('N' & 0xff);
	DELAY(2000);
	DELAY(2000);
	*(volatile uint8_t *)(io3c_base + com_data) = (u_int8_t)('e' & 0xff);
	DELAY(2000);
	DELAY(2000);
	*(volatile uint8_t *)(io3c_base + com_data) = (u_int8_t)('t' & 0xff);
	DELAY(2000);
	DELAY(2000);
	*(volatile uint8_t *)(io3c_base + com_data) = (u_int8_t)('B' & 0xff);
	DELAY(2000);
	DELAY(2000);
	*(volatile uint8_t *)(io3c_base + com_data) = (u_int8_t)('S' & 0xff);
	DELAY(2000);
	DELAY(2000);
	*(volatile uint8_t *)(io3c_base + com_data) = (u_int8_t)('D' & 0xff);
	DELAY(2000);
	DELAY(2000);
	*(volatile uint8_t *)(io3c_base + com_data) = (0x0A & 0xff);
	DELAY(2000);
#endif
}