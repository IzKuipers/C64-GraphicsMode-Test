#include <c64/vic.h>

const unsigned SCREEN_WIDTH = 320;
const unsigned SCREEN_HEIGHT = 200;
const unsigned SCREEN_WIDTH_ZB = 319;
const unsigned SCREEN_HEIGHT_ZB = 199;
int DEF_GFX_BOUNDS[4] = {0, 0, SCREEN_HEIGHT, SCREEN_WIDTH}; // top, left, bottom, right
char * const Hires	= (char *)0xe000;
char * const Screen	= (char *)0xd000;

void set(int x, int y)
{
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		char* dp = Hires + 40 * 8 * (y >> 3) + (y & 7) + (x & ~7);
		*dp |= 0x80 >> (x & 7);
	}
}

void draw_hline(int x, int y, int len) {
    for (int i = x; i < x + len; i++) {
        set(i, y);
    }
}

void draw_vline(int x, int y, int len) {
    for (int i = y; i < y + len; i++){
        set(x, i);
    }
}

void draw_box(int x, int y, int w, int h, int p, int *bounds) {
    draw_hline(x, y, w); // top
    draw_hline(x, y + h, w); // bottom
    draw_vline(x, x, h); // left
    draw_vline(x + w, x, h); // right

    // tlbr
    bounds[0] = y + p + 1; // top
    bounds[1] = x + p + 1; // left
    bounds[2] = h - p - 1; // bottom
    bounds[3] = (x + w) - p - 1; // right
}