//
// brin_demo.c
// Essential tilemap loading: the start of brinstar from metroid 1
//
// (20060221 - 20070216, cearn)

#include <string.h>

#include <tonc.h>
#include "brin.h"

int main()
{
	// Load palette
	memcpy16(pal_bg_mem, brinPal, brinPalLen / sizeof(u16));
	// Load tiles into CBB 0
	memcpy32(&tile_mem[0][0], brinTiles, brinTilesLen / sizeof(u32));
	// Load map into SBB 30
	memcpy32(&se_mem[30][0], brinMap, brinMapLen / sizeof(u32));

	// set up BG0 for a 4bpp 64x32t map, using
	//   using charblock 0 and screenblock 31
	REG_BG0CNT= BG_CBB(0) | BG_SBB(30) | BG_4BPP | BG_REG_64x32;
	REG_DISPCNT= DCNT_MODE0 | DCNT_BG0;

	// Scroll around some
	int x= 192, y= 64;
	while(1)
	{
		vid_vsync();
		key_poll();

		x += key_tri_horz();
		y += key_tri_vert();

		REG_BG0HOFS= x;
		REG_BG0VOFS= y;
	}

	return 0;
}
