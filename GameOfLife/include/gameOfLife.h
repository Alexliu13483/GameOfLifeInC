/*
 * gameOfLife.h
 *
 *  Created on: 2018¦~10¤ë16¤é
 *      Author: Alex.Liu
 */

#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_
#include <stdbool.h>


#define ALIVE_CELL	'*'

void gol_createGrid(int width, int height);
void gol_distroyGrid();
int gol_countAlives(int x, int y);
void gol_setAlive(int x, int y);

#endif /* GAMEOFLIFE_H_ */
