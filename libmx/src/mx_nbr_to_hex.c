#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr)
{
	char hex_symbols[] = "0123456789abcdef";
	char hex_buff[65]; // 64 + '\0';
	int hex_index = 64;

	if(nbr == 0)
	{
		char *hex_output = (char *)malloc(2);
		hex_output[0] = '0';
		hex_output[1] = '\0';

		return hex_output;
	}

	hex_buff[hex_index--] = '\0';

	while(nbr > 0)
	{
		hex_buff[hex_index--] = hex_symbols[nbr % 16];
		nbr /= 16;
	}

	int hex_len = 64 - hex_index - 1;
	char *hex_output = (char *)malloc(hex_len + 1);

	for(int i = 0; i < hex_len; i++)
	{
		hex_output[i] = hex_buff[hex_index + 1 + i];
	}

	hex_output[hex_len] = '\0';

	return hex_output;
}

