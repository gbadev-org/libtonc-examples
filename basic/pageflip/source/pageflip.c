//
// pageflip.c
// Shows mode4 page flipping
//
// (20031003 - 20060922, Cearn)
// (20221114, AntonioND)

#include <string.h>

#include <tonc.h>
#include "page_pic.h"

void load_gfx()
{
	const size_t bitmap_size = page_picBitmapLen / (2 * sizeof(unsigned int));
	const unsigned int *frontBitmap = page_picBitmap;
	const unsigned int *backBitmap = frontBitmap + bitmap_size;

	int ii;
	for(ii=0; ii<16; ii++)
	{
		memcpy32(&vid_mem_front[ii*120], &frontBitmap[ii*144/4], 144/4);
		memcpy32(&vid_mem_back[ii*120], &backBitmap[ii*144/4], 144/4);
	}

	memcpy16(&pal_bg_mem[0], page_picPal, page_picPalLen/2);
}

int main()
{
	load_gfx();
	REG_DISPCNT= DCNT_MODE4 | DCNT_BG2;

	int ii=0;

	while(1)
	{
		while(KEY_DOWN_NOW(KEY_START)) ;	// pause with start

		vid_vsync();
		if(++ii == 60)
		{
			ii=0;
			vid_flip();
		}
	}

	return 0;
}
