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

static int gol_calCellIndex(int x, int y) {
	assert(x < gridWidth && x >= 0);
	assert(y < gridHeight && y >= 0);

	return gridWidth * y + x;
}

bool gol_isAlive(int x, int y) {
	if (x < 0 || y < 0 || x >= gridWidth || y >= gridHeight)
		return false;

	if (grid[gol_calCellIndex(x, y)] == ALIVE_CELL)
		return true;
	return false;
}

int gol_countAlives(int x, int y) {
	int count = 0;

	if (gol_isAlive(x-1, y-1) == true)
		count++;
	if (gol_isAlive(x, y-1) == true)
		count++;
	if (gol_isAlive(x+1, y-1) == true)
		count++;
	if (gol_isAlive(x-1, y) == true)
		count++;
	if (gol_isAlive(x+1, y) == true)
		count++;
	if (gol_isAlive(x-1, y+1) == true)
		count++;
	if (gol_isAlive(x, y+1) == true)
		count++;
	if (gol_isAlive(x+1, y+1) == true)
		count++;

	return count;
}

void gol_setAlive(int x, int y) {
	grid[gol_calCellIndex(x, y)] = ALIVE_CELL;
}
