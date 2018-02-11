#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
    if (x1 < x0) {
        int swap = x0;
        x0 = x1;
        x1 = swap;

        swap = y0;
        y0 = y1;
        y1 = swap;
    }

    int A = y1 - y0;
    int B = x0 - x1;
    float m = 1000;
    if (B) {
        m = (float) A / B * -1;
    } else if (y1 < y0) {
        m = -1000;
    }

    if (m > 1) {
        //printf("m = %f: drawing in O II from %d %d to %d %d\n", m, x0, y0, x1, y1);
        draw_line_octant_II(x0, y0, x1, y1, s, c);
    } else if (m > 0) {
        //printf("m = %f: drawing in O I from %d %d to %d %d\n", m, x0, y0, x1, y1);
        draw_line_octant_I(x0, y0, x1, y1, s, c);
    } else if (m > -1) {
        //printf("m = %f: drawing in O VIII from %d %d to %d %d\n", m, x0, y0, x1, y1);
        draw_line_octant_VIII(x0, y0, x1, y1, s, c);
    } else {
        //printf("m = %f: drawing in O VII from %d %d to %d %d\n", m, x0, y0, x1, y1);
        draw_line_octant_VII(x0, y0, x1, y1, s, c);
    }
}

void draw_line_octant_I(int x0, int y0, int x1, int y1, screen s, color c) {
    int A = y1 - y0;
    int B = x0 - x1;

    int x = x0;
    int y = y0;

    int d = 2*A + B;
    while (x <= x1) {
        plot(s, c, x, y);
        if ( d > 0 ) {
            y++;
            d += 2*B;
        }
        x++;
        d += 2*A;
    }
}

void draw_line_octant_II(int x0, int y0, int x1, int y1, screen s, color c) {
    int A = y1 - y0;
    int B = x0 - x1;

    int x = x0;
    int y = y0;

    int d = A + 2*B;
    while (y <= y1) {
        plot(s, c, x, y);
        if ( d < 0 ) {
            x++;
            d += 2*A;
        }
        y++;
        d += 2*B;
    }

}

void draw_line_octant_VII(int x0, int y0, int x1, int y1, screen s, color c) {
    int A = y1 - y0;
    int B = x0 - x1;

    int x = x0;
    int y = y0;

    int d = A - 2*B;
    while (y >= y1) {
        plot(s, c, x, y);
        if ( d > 0 ) {
            x++;
            d += 2*A;
        }
        y--;
        d -= 2*B;
    }

}

void draw_line_octant_VIII(int x0, int y0, int x1, int y1, screen s, color c) {
    int A = y1 - y0;
    int B = x0 - x1;

    int x = x0;
    int y = y0;

    int d = 2*A - B;
    while (x <= x1) {
        plot(s, c, x, y);
        if ( d < 0 ) {
            y--;
            d -= 2*B;
        }
        x++;
        d += 2*A;
    }

}
