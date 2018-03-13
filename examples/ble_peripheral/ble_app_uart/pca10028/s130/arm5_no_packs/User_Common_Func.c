#include "User_Common_Func.h"

#include "ble_gap.h"
#include "app_error.h"


void Mac_Addr_Set(void)
{
    uint8_t i = 0;
    uint8_t mac_addr[8];
    uint32_t err_code;
    ble_gap_addr_t gap_addr;
    const uint8_t *addr = (uint8_t *)0x100010f8;

    gap_addr.addr_type = BLE_GAP_ADDR_TYPE_PUBLIC;
    memcpy(gap_addr.addr, mac_addr, 6); 			

    err_code = sd_ble_gap_address_set(BLE_GAP_ADDR_CYCLE_MODE_NONE, &gap_addr);
    APP_ERROR_CHECK(err_code);	
}


// »ñÈ¡mac µØÖ·
void get_mac_addr(uint8_t *p_mac_addr)
{
    uint32_t error_code;
    ble_gap_addr_t p_mac_addr_t ;
    error_code = sd_ble_gap_address_get(&p_mac_addr_t);
    APP_ERROR_CHECK(error_code);
    uint8_t *d = p_mac_addr_t.addr;
    for ( uint8_t i = 6; i >0;)
    {	
        i--;
        p_mac_addr[5-i]= d[i];
        //printf("0x%02x ",p_mac_addr[5-i]);
    }
}

char *HexToStr( uint8_t *pAddr )
{
		uint8_t       i,len;
		char        hex[] = "0123456789ABCDEF";
		static char str[50];
		char        *pStr = str;
		*pStr++ = '0';
		*pStr++ = 'x';
		 len = strlen((char *)pAddr);

		for ( i = 0; i < len; i++ )
		{ 
			*pStr++ = hex[((uint8_t)(*pAddr) >> 4) &0x0F];
			*pStr++ = hex[(uint8_t)*pAddr & 0x0F];
			pAddr++;
		}

		*pStr = 0;

		return str;
}
