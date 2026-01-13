#include <c64/vic.h>

char * const Hires	= (char *)0xe000;
char * const Screen	= (char *)0xd000;

void set(int x, int y)
{
	if (x >= 0 && x < 320 && y >= 0 && y < 200)
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
