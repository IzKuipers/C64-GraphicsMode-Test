#include "pixel.c"

const unsigned TERMINATOR_BYTE = 0xFF;
const unsigned MAX_CHAR_WIDTH = 5;
const unsigned CHAR_HEIGHT = 8;
const unsigned CHAR_SPACING = 1;

const char* FontMap = "\xFFabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ '\",.0123456789%@()[]{}:?;#$=+-~/\\|><`";
static const char FontData[] = {
	#embed "../fonts/abc2-lowercase.bin"
};

int find_fontdata_idx(int idx) {
    int counter = idx;
    int start = 0;

    for (int i = 0; i < sizeof(FontData); i++) {
        char byte = FontData[i];

        if (byte == TERMINATOR_BYTE) {
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
    int start = find_fontdata_idx(idx);
    int width = 0;

    if (start == -1) return 0;

    for (int i = 0; i < sizeof(FontData); i++) {
        char byte = FontData[start + i];
        if (byte == TERMINATOR_BYTE) break;

        int bit = 0;
        while (bit < 8) {
            if (byte & 0x01) {
                set(x + i, y + (8 - bit) - 1);
            }

            bit++;
            byte = byte >> 1;
        }

        width++;
    }

    return width;
}

int fontmap_idx(char c) {
    for (int i = 0; FontMap[i]; i++) {
        if (FontMap[i] == c)
            return i;
    }
    return 0;
}

int gfx_print(int x, int y, const char* sequence) {
    int end = 0;

    for (int i = 0 ; i < strlen(sequence); i++) {
        int idx = fontmap_idx(sequence[i]);
        int width = put_char(idx, x, y);

        x += width + CHAR_SPACING;
        end += width + CHAR_SPACING;
    }

    return end;
}

int gfx_print_in(const char* sequence, int bounds[4]) {
    int x = bounds[1];
    int y = bounds[0];
    int top_boundary = bounds[0];
    int left_boundary = bounds[1];
    int bottom_boundary = bounds[2];
    int right_boundary = bounds[3];
    int initial_x = x;
    int initial_y = y;

    int end = 0;

    for (int i = 0; i < strlen(sequence); i++) {
        bool is_newline = sequence[i] == '\n';

        if (x + MAX_CHAR_WIDTH >= right_boundary || is_newline) {
            x = initial_x;
            y += CHAR_HEIGHT;

            if (y >= initial_y + bottom_boundary) break;
            if (is_newline) continue;
        }

        int idx = fontmap_idx(sequence[i]);
        int width = put_char(idx, x, y);

        x += width + CHAR_SPACING;
        end += width + CHAR_SPACING;
    }

    return end;
}

void gfx_testprint() {
    gfx_print_in(FontMap, DEF_GFX_BOUNDS);
}