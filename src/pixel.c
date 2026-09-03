const unsigned SCREEN_WIDTH = 320;
const unsigned SCREEN_HEIGHT = 200;
const unsigned SCREEN_WIDTH_ZB = 319;
const unsigned SCREEN_HEIGHT_ZB = 199;
int DEF_GFX_BOUNDS[4] = {2, 2, SCREEN_HEIGHT - 2, SCREEN_WIDTH - 2};
char *const Hires = (char *)0xe000;
char *const Screen = (char *)0xd000;
unsigned row_start[25];
const unsigned char bit_mask[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
const unsigned char bit_mask_inv[8] = {0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE};

void init_screen_tables(void)
{
	unsigned a = 0;
	for (char i = 0; i < 25; i++)
	{
		row_start[i] = a;
		a += 320;
	}
}

void set(int x, int y)
{
	if ((unsigned)x < SCREEN_WIDTH && (unsigned)y < SCREEN_HEIGHT)
	{
		char *dp = Hires + row_start[y >> 3] + (y & 7) + (x & ~7);
		*dp |= bit_mask[x & 7];
	}
}

void clear(int x, int y)
{
	if ((unsigned)x < SCREEN_WIDTH && (unsigned)y < SCREEN_HEIGHT)
	{
		char *dp = Hires + row_start[y >> 3] + (y & 7) + (x & ~7);
		*dp &= bit_mask_inv[x & 7];
	}
}
