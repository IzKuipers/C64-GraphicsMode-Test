const char* FontMap = "abcdefghijklmnopqrstuvwxyz";

static const char FontData[] = {
	#embed "./fonts/abc2-lowercase.bin"
};

int find_fontdata_idx(int idx) {
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
    int start = find_fontdata_idx(idx);
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

int fontmap_idx(char c) {
    for (int i = 0; FontMap[i]; i++) {
        if (FontMap[i] == c)
            return i;
    }
    return -1;
}

void gfx_print(int x, int y, const char* sequence) {
    for (int i = 0; i < strlen(sequence); i++) {
        int idx = fontmap_idx(sequence[i]);

        if (idx == -1) {
            x += 1;
            continue;
        }

        int width = put_char(idx, x, y);
        x += width + 1;
    }
}
