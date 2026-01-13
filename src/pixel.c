const unsigned SCREEN_WIDTH = 320;
const unsigned SCREEN_HEIGHT = 200;
const unsigned SCREEN_WIDTH_ZB = 319;
const unsigned SCREEN_HEIGHT_ZB = 199;
int DEF_GFX_BOUNDS[4] = {2, 2, SCREEN_HEIGHT - 2, SCREEN_WIDTH - 2}; // top, left, bottom, right
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
