#ifndef SLIDELINE_H
#define SLIDELINE_H

#include <stdlib.h>
#include <stdio.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

void left_move(int *line, size_t size);
void right_move(int *line, size_t size);
int slide_line(int *line, size_t size, int direction);

#endif
