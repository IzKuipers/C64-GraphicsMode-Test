#include <c64/vic.h>
#include <c64/memmap.h>
#include <math.h>
#include <string.h>
#include "graphics.c"
#include "fontrenderer.c"

int main(void)
{
	mmap_trampoline();
	mmap_set(MMAP_RAM);
	memset(Screen, 0x01, 1000);
	memset(Hires, 0x00, 8000);
	mmap_set(MMAP_NO_ROM);
	vic_setmode(VICM_HIRES, Screen, Hires);
	vic.color_border = VCOL_WHITE;

    // Draw a border at the screen edge
    draw_hline(0, 0, 320);
    draw_hline(0, 199, 320);
    draw_vline(0, 0, 200);
    draw_vline(319, 0, 200);
    
    // Print out the alphabet
    gfx_print(2, 2, "abcdefghijklmnopqrstuvwxyz");

    // Loop infinitely to prevent the program from stopping
    for(;;) {}

	return 0;
}