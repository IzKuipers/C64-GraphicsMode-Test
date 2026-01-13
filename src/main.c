#include <c64/vic.h>
#include <c64/memmap.h>
#include <math.h>
#include <string.h>
#include "graphics.c"
#include "fontrenderer.c"
#include "util.c"

int main(void)
{
	mmap_trampoline();
	mmap_set(MMAP_RAM);
	memset(Screen, 0x01, 1000);
	memset(Hires, 0x00, 8000);
	mmap_set(MMAP_NO_ROM);
	vic_setmode(VICM_HIRES, Screen, Hires);
	vic.color_border = VCOL_BLACK;
	vic.color_back = VCOL_BLACK;

    int siz[1] = { strlen(FontMap) };
    debug_print(siz, 1);

    int bounds[4];
    draw_box(30, 30, 140, 80, 5, bounds);
    gfx_print_in("An error occurred, and the operation couldn't be completed.", bounds);

    // Loop infinitely to prevent the program from stopping
    for(;;) {}

	return 0;
}