#include <c64/vic.h>
#include <c64/memmap.h>
#include <math.h>
#include <string.h>

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
    for (int i=x;i<x+len;i++) {
        set(i, y);
    }
}

void draw_vline(int x, int y, int len) {
    for (int i=y; i<y+len;i++){
        set(x, i);
    }
}

int main(void)
{
	mmap_trampoline();
	mmap_set(MMAP_RAM);
	memset(Screen, 0x01, 1000);
	memset(Hires, 0x00, 8000);
	mmap_set(MMAP_NO_ROM);
	vic_setmode(VICM_HIRES, Screen, Hires);
	vic.color_border = VCOL_WHITE;

    draw_hline(0, 0, 320);
    draw_hline(0, 12, 320);

    draw_hline(0, 199, 320);
    draw_vline(0, 0, 200);
    draw_vline(319, 0, 200);

    for (;;){}

	return 0;
}