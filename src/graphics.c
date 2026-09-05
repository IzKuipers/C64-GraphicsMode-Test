#include <c64/vic.h>
#include "fontrenderer.c"
#include "util.c"

void draw_hline(int x, int y, int len)
{
    for (int i = x; i < x + len; i++)
    {
        set(i, y);
    }
}

void draw_vline(int x, int y, int len)
{
    int y1 = y, y2 = y + len;
    if ((unsigned)x >= SCREEN_WIDTH)
        return;
    if (y1 < 0)
        y1 = 0;
    if (y2 > (int)SCREEN_HEIGHT)
        y2 = SCREEN_HEIGHT;
    if (y1 >= y2)
        return;

    char *dp = Hires + row_start[y1 >> 3] + (y1 & 7) + (x & ~7);
    unsigned char mask = bit_mask[x & 7];
    char sub = y1 & 7;
    for (int i = y1; i < y2; i++)
    {
        *dp |= mask;
        sub++;
        if (sub == 8)
        {
            sub = 0;
            dp += 320 - 7;
        }
        else
            dp++;
    }
}

void clear_area(int x, int y, int w, int h)
{
    int x1 = x, y1 = y;
    int x2 = x + w; // inclusive, matches original off-by-one behavior
    int y2 = y + h;

    if (x1 < 0)
        x1 = 0;
    if (y1 < 0)
        y1 = 0;
    if (x2 > (int)SCREEN_WIDTH_ZB)
        x2 = SCREEN_WIDTH_ZB;
    if (y2 > (int)SCREEN_HEIGHT_ZB)
        y2 = SCREEN_HEIGHT_ZB;
    if (x1 > x2 || y1 > y2)
        return;

    int bx1 = x1 >> 3;
    int bx2 = x2 >> 3;
    unsigned char lmask = 0xFF >> (x1 & 7);
    unsigned char rmask = (unsigned char)~(0x7F >> (x2 & 7));

    for (int yy = y1; yy <= y2; yy++)
    {
        unsigned base = row_start[yy >> 3] + (yy & 7);
        char *dp = Hires + base + bx1 * 8;

        if (bx1 == bx2)
        {
            *dp &= (unsigned char)~(lmask & rmask);
        }
        else
        {
            *dp &= (unsigned char)~lmask; // left partial byte
            dp += 8;
            int n = bx2 - bx1 - 1; // full bytes in between
            while (n--)
            {
                *dp = 0;
                dp += 8;
            }
            *dp &= (unsigned char)~rmask; // right partial byte
        }
    }
}

void draw_checkerboard(int x, int y, int w, int h)
{
    int x1 = x, y1 = y;
    int x2 = x + w; // exclusive
    int y2 = y + h; // exclusive

    if (x1 < 0)
        x1 = 0;
    if (y1 < 0)
        y1 = 0;
    if (x2 > (int)SCREEN_WIDTH)
        x2 = SCREEN_WIDTH;
    if (y2 > (int)SCREEN_HEIGHT)
        y2 = SCREEN_HEIGHT;
    if (x1 >= x2 || y1 >= y2)
        return;

    int bx1 = x1 >> 3;
    int bx2 = (x2 - 1) >> 3; // index of last touched byte

    unsigned char lmask = 0xFF >> (x1 & 7);                // bits from x1 to end of byte
    unsigned char r = (unsigned char)(((x2 - 1) & 7) + 1); // # included bits in last byte
    unsigned char rmask = (unsigned char)(0xFF << (8 - r));

    for (int yy = y1; yy < y2; yy++)
    {
        unsigned char patt = (yy & 1) ? 0x55 : 0xAA;
        unsigned base = row_start[yy >> 3] + (yy & 7);
        char *dp = Hires + base + bx1 * 8;

        if (bx1 == bx2)
        {
            unsigned char m = lmask & rmask;
            *dp = (unsigned char)((*dp & ~m) | (patt & m));
        }
        else
        {
            // left partial byte
            *dp = (unsigned char)((*dp & ~lmask) | (patt & lmask));
            dp += 8;

            // fully-covered bytes: straight overwrite, no merge needed
            int n = bx2 - bx1 - 1;
            while (n--)
            {
                *dp = patt;
                dp += 8;
            }

            // right partial byte
            *dp = (unsigned char)((*dp & ~rmask) | (patt & rmask));
        }
    }
}

void draw_box(int x, int y, int w, int h, int p, int *bounds)
{
    draw_hline(x, y, w);
    draw_hline(x, y + h, w + 1);
    draw_vline(x, y, h);
    draw_vline(x + w, y, h);

    bounds[0] = y + p + 1; // ypos
    bounds[1] = x + p + 1; // xpos
    bounds[2] = (y + h) - p - 1; // ypos+h
    bounds[3] = (x + w) - p - 1; // width
}

void draw_window(int x, int y, int w, int h, int p, int *content_bounds, const char *title)
{
    int window_bounds[4];
    int title_bounds[4];
    int body_bounds[4];
    int titlebar_height = 12;

    clear_area(x, y, w, h);
    draw_box(x, y, w, h, 0, window_bounds);
    draw_box(x, y, w, titlebar_height, 2, title_bounds);
    draw_box(x, y + titlebar_height, w, h - titlebar_height, p, body_bounds);
    gfx_print_in(title, title_bounds);

    content_bounds[0] = body_bounds[0];
    content_bounds[1] = body_bounds[1];
    content_bounds[2] = body_bounds[2];
    content_bounds[3] = body_bounds[3];
}

void draw_window_centered(int w, int h, int p, int *content_bounds, const char *title)
{
    int x = (SCREEN_WIDTH - w) / 2;
    int y = (SCREEN_HEIGHT - h) / 2;
    draw_window(x, y, w, h, p, content_bounds, title);
}