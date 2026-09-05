#include <c64/vic.h>
#include <c64/memmap.h>
#include <c64/sprites.h>
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
    init_screen_tables();
    vic.color_border = VCOL_DARK_GREY;

    clear_area(0, 0, SCREEN_WIDTH_ZB, SCREEN_HEIGHT_ZB);
    draw_checkerboard(0, 0, SCREEN_WIDTH_ZB, SCREEN_HEIGHT_ZB);

    int screen_bounds[4];
    draw_box(0, 0, SCREEN_WIDTH_ZB, SCREEN_HEIGHT_ZB, 0, screen_bounds);

    int body_bounds[4];
    draw_window_centered(140, 80, 5, body_bounds, "About");
    int end = gfx_print_in("UI rendering test\nversion 1.0\n\n(c) Izaak Kuipers 2026", body_bounds);

    // Loop infinitely to prevent the program from stopping
    for (;;)
    {
    }

    return 0;
}