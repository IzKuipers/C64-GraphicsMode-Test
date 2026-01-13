#include <stdio.h>

void debug_print(int input[], int s) {
    int pos = gfx_print_in("DEBUG: ", DEF_GFX_BOUNDS);

    for (int i = 0; i < s; i++) {
        char dest[50];

        sprintf(dest, "%d, ", input[i]);

        int bounds[4] = { DEF_GFX_BOUNDS[0], pos, SCREEN_HEIGHT, SCREEN_WIDTH};

        pos += gfx_print_in(dest, bounds);
    }
}