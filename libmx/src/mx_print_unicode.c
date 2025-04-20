#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c)
{
	unsigned char bytes_temp[4];
	int bytes_len;

	if(c < 0x80)
	{
		bytes_temp[0] = (unsigned char)c;
        bytes_len = 1;
	} else if(c < 0x800)
	{
		bytes_temp[0] = (unsigned char)((c >> 6) | 0xc0);
		bytes_temp[1] = (unsigned char)((c & 0x3f) | 0x80);
		bytes_len = 2;
	} else if(c < 0x10000)
	{
		bytes_temp[0] = (unsigned char)((c >> 12) | 0xe0);
        bytes_temp[1] = (unsigned char)(((c >> 6) & 0x3f) | 0x80);
        bytes_temp[2] = (unsigned char)((c & 0x3f) | 0x80);
        bytes_len = 3;
	} else if(c < 0x110000)
	{
		bytes_temp[0] = (unsigned char)((c >> 18) | 0xf0);
        bytes_temp[1] = (unsigned char)(((c >> 12) & 0x3f) | 0x80);
        bytes_temp[2] = (unsigned char)(((c >> 6) & 0x3f) | 0x80);
        bytes_temp[3] = (unsigned char)((c & 0x3f) | 0x80);
        bytes_len = 4;
	} else
	{
		return;
	}

	write(1, bytes_temp, bytes_len);
}

