//
// bm_modes.c
// Combined demo of modes 3, 4 and 5
//
// (20031002 - 20060922, cearn)

// This example is a hack. Normally you aren't supposed to have a bitmap that is
// used in different modes. Modes 3 and 5 use 16 BPP images so they could, in
// theory, share graphics. However, mode 4 uses 8 BPP images.

#include <string.h>
#include <tonc.h>
#include "modes.h"
#include "modes_pal.h"

int main()
{
	int mode= 3;
	REG_DISPCNT= mode | DCNT_BG2;

	// Copy the data and palette to the right
	// addresses
	memcpy32(vid_mem, modesBitmap, modesBitmapLen / sizeof(u32));
	memcpy16(pal_bg_mem, modes_palPal, modes_palPalLen / sizeof(u16));

	while(1)
	{
		// Wait till VBlank before doing anything
		vid_vsync();

		// Check keys for mode change
		key_poll();
		if(key_hit(KEY_LEFT) && mode>3)
			mode--;
		else if(key_hit(KEY_RIGHT) && mode<5)
			mode++;

		// Change the mode
		REG_DISPCNT= mode | DCNT_BG2;
	}

	return 0;
}
