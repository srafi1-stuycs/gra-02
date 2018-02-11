#include "ml6.h"

#ifndef DRAW_H
#define DRAW_H

void draw_line(int x0, int y0, int x1, int y1, screen s, color c);
void draw_line_octant_I(int x0, int y0, int x1, int y1, screen s, color c);
void draw_line_octant_II(int x0, int y0, int x1, int y1, screen s, color c);
void draw_line_octant_VII(int x0, int y0, int x1, int y1, screen s, color c);
void draw_line_octant_VIII(int x0, int y0, int x1, int y1, screen s, color c);

#endif
