/*
 * gameOfLife.c
 *
 *  Created on: 2018¦~10¤ë16¤é
 *      Author: Alex.Liu
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "gameOfLife.h"

static char *grid = NULL;
static int gridWidth = 0;
static int gridHeight = 0;

void gol_createGrid(int width, int height) {
	gridWidth = width;
	gridHeight = height;
	grid = (char *)calloc(width*height, sizeof(char));
}

void gol_distroyGrid() {
	free(grid);
	gridWidth = 0;
	gridHeight = 0;
}

int gol_countAlive() {
	int count = 0;

	for (int i = 0; i < gridWidth * gridHeight; i++)
		if (grid[i] != 0)
			count++;
	return count;
}

void gol_setCell(int x, int y) {
	assert(x < gridWidth);
	assert(y < gridHeight);

	grid[gridWidth * y + x] = ALIVE_CELL;
}
