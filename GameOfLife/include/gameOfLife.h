/*
 * gameOfLife.h
 *
 *  Created on: 2018¦~10¤ë16¤é
 *      Author: Alex.Liu
 */

#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_

#define ALIVE_CELL	'*'

void gol_createGrid(int width, int height);
void gol_distroyGrid();
int gol_countAlive();
void gol_setCell(int x, int y);

#endif /* GAMEOFLIFE_H_ */
