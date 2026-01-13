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

const char* FontMap = "abcdefghijklmnopqrstuvwxyz";

static const char FontData[] = {
	#embed "./fonts/abc2-lowercase.bin"
};

int find_char_idx(int idx) {
    int counter = idx;
    int start = 0;

    for (int i = 0; i < sizeof(FontData); i++) {
        char byte = FontData[i];

        if (byte == 0xFF) {
            counter--;
            start = i + 1;
            continue;
        }

        if (counter == 0) break;
    }

    if (counter != 0) return -1;

    return start;
}

int put_char(int idx, int x, int y) {
    int start = find_char_idx(idx);
    int width = 0;

    if (start == -1) return 0;

    for (int i=0;i<sizeof(FontData);i++) {
        char byte = FontData[start + i];
        if (byte == 0xFF) break;

        int bit = 0;
        while (bit < 8) {
            if (byte & 0x01) {
                set(x+i, y + (8 - bit));
            }

            bit++;
            byte = byte >> 1;
        }

        width++;
    }

    return width;
}

int character_idx(char c) {
    for (int i = 0; FontMap[i]; i++) {
        if (FontMap[i] == c)
            return i;
    }
    return -1;
}

void gfx_print(int x, int y, const char* sequence) {
    for (int i = 0; i < strlen(sequence); i++) {
        int width = put_char(character_idx(sequence[i]), x, y);
        x += width + 1;
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