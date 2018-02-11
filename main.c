#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

    screen s;
    color c;
    c.red = MAX_COLOR;
    c.blue = MAX_COLOR;
    c.green = MAX_COLOR;

    clear_screen(s);

    /*
    //initial testing
    int i;
    int x0 = 250;
    int y0 = 250;
    int x1 = 400;
    int y1 = 250;

    for (i = 0; i < 10; i++) {
        draw_line(x0, y0, x1, y1, s, c);
        x1 -= 15;
        y1 += 15;
        c.red -= 5;
        c.blue -= 5;
        c.green -= 5;
    }
    for (i = 0; i < 10; i++) {
        draw_line(x0, y0, x1, y1, s, c);
        x1 -= 15;
        y1 -= 15;
        c.red -= 5;
        c.blue -= 5;
        c.green -= 5;
    }
    for (i = 0; i < 10; i++) {
        draw_line(x0, y0, x1, y1, s, c);
        x1 += 15;
        y1 -= 15;
        c.red -= 5;
        c.blue -= 5;
        c.green -= 5;
    }
    for (i = 0; i < 10; i++) {
        draw_line(x0, y0, x1, y1, s, c);
        x1 += 15;
        y1 += 15;
        c.red -= 5;
        c.blue -= 5;
        c.green -= 5;
    }
    */

    int i;
    int x0 = 220;
    int y0 = 500;
    int x1 = 220;
    int y1 = 0;
    printf("checkpoint 0: %d %d %d %d\n", x0, y0, x1, y1);

    c.red = MAX_COLOR;
    c.green = 0;
    c.blue = 0;
    for (int i = 0; i < 20; i++) {
        x0 -= 11;
        y0 -= 14;
        x1 += 14;
        y1 += 11;
        c.red -= 7;
        printf("\tred: %d %d to %d %d\n", x0, y0, x1, y1);
        draw_line(x0, y0, x1, y1, s, c);
    }
    printf("checkpoint 1: %d %d %d %d\n", x0, y0, x1, y1);

    c.red = 0;
    c.green = MAX_COLOR;
    c.blue = 0;
    for (int i = 0; i < 20; i++) {
        x0 += 14;
        y0 -= 11;
        x1 -= 11;
        y1 += 14;
        c.green -= 7;
        printf("\tgreen: %d %d to %d %d\n", x0, y0, x1, y1);
        draw_line(x0, y0, x1, y1, s, c);
    }
    printf("checkpoint 2: %d %d %d %d\n", x0, y0, x1, y1);

    c.red = 0;
    c.green = 0;
    c.blue = MAX_COLOR;
    for (int i = 0; i < 20; i++) {
        x0 += 11;
        y0 += 14;
        x1 -= 14;
        y1 -= 11;
        c.blue -= 7;
        printf("\tblue: %d %d to %d %d\n", x0, y0, x1, y1);
        draw_line(x0, y0, x1, y1, s, c);
    }
    printf("checkpoint 3: %d %d %d %d\n", x0, y0, x1, y1);

    c.red = MAX_COLOR;
    c.green = MAX_COLOR;
    c.blue = 0;
    for (int i = 0; i < 20; i++) {
        x0 -= 14;
        y0 += 11;
        x1 += 11;
        y1 -= 14;
        c.red -= 7;
        c.green -= 7;
        printf("\twhite: %d %d to %d %d\n", x0, y0, x1, y1);
        draw_line(x0, y0, x1, y1, s, c);
    }
    printf("checkpoint 4: %d %d %d %d\n", x0, y0, x1, y1);

    display(s);
    save_extension(s, "lines.png");
}
