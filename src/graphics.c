#include <c64/vic.h>
#include "fontrenderer.c"
#include "util.c"

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
    draw_hline(x, y + h, w+1); // bottom
    draw_vline(x, x, h); // left
    draw_vline(x + w, x, h); // right

    // tlbr
    bounds[0] = y + p + 1; // top
    bounds[1] = x + p + 1; // left
    bounds[2] = h - p - 1; // bottom
    bounds[3] = (x + w) - p - 1; // right
}

void draw_window(int x, int y, int w, int h, int p, int *content_bounds, const char* title) {
    // h + char height + title padding + bottom border
    
    int window_bounds[4];
    int title_bounds[4];
    int body_bounds[4];

    int titlebar_height = 12;

    draw_box(x, y, w, h, 0, window_bounds);
    draw_box(x, y, w, titlebar_height, 2, title_bounds);
    draw_box(x, y + titlebar_height, w, h - titlebar_height, p, body_bounds);
    gfx_print_in(title, title_bounds);
    gfx_print(x + w - 5 - 3, y + 3, "*");

    int debug[] = { x, y, w, h, p, sizeof(content_bounds), strlen(title) };

    debug_print(debug, 7);
    
    content_bounds[0] = body_bounds[0];
    content_bounds[1] = body_bounds[1];
    content_bounds[2] = body_bounds[2];
    content_bounds[3] = body_bounds[3];
}