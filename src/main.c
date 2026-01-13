#include <c64/vic.h>
#include <c64/memmap.h>
#include <math.h>
#include <string.h>
#include "graphics.c"

int main(void)
{
	mmap_trampoline();
	mmap_set(MMAP_RAM);
	memset(Screen, 0x01, 1000);
	memset(Hires, 0x00, 8000);
	mmap_set(MMAP_NO_ROM);
	vic_setmode(VICM_HIRES, Screen, Hires);
	vic.color_border = VCOL_DARK_GREY;

    int screen_bounds[4];
    draw_box(0, 0, SCREEN_WIDTH_ZB, SCREEN_HEIGHT_ZB, 0, screen_bounds);

    int body_bounds[4];
    draw_window(30, 30, 140, 80, 5, body_bounds, "Errorg");
    int end = gfx_print_in("An error occurred, and the\noperation couldn't be\ncompleted.", body_bounds);

    // Loop infinitely to prevent the program from stopping
    for(;;) {}

	return 0;
}