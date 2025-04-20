#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex)
{
	unsigned long hex_output = 0;

	if(hex == NULL)
	{
		return 0;
	}

	while(*hex)
	{
		hex_output *= 16;

		if(*hex >= '0' && *hex <= '9')
		{
			hex_output += *hex - '0';
		} else if(*hex >= 'A' && *hex <= 'F')
		{
			hex_output += *hex - 'A' + 10;
		} else if(*hex >= 'a' && *hex <= 'f')
		{
			hex_output += *hex - 'a' + 10;
		} else
		{
			return 0;
		}
		hex++;
	}
	return hex_output;
}
