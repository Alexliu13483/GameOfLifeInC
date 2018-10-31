/*
 * testGameOfLife.cpp
 *
 *  Created on: 2018¦~10¤ë16¤é
 *      Author: Alex.Liu
 */

/* Useful CppUTest Assert Functions
 * 	STRCMP_EQUAL(expect, result);
 * 	LONGS_EQUAL(expect, result);
 * 	BYTES_EQUAL(expect, result);
 * 	POINTERS_EQUAL(expect, result);
 *  DOUBLES_EQUAL(expected,actual,threshold);
 */



extern "C"
{
#include "gameOfLife.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(testGameOfLife_8x4)
{
	int gridWidth = 8;
	int gridHeight = 4;

    void setup()
    {
    	gol_createGrid(gridWidth, gridHeight);
    }

    void teardown()
    {
    	gol_distroyGrid();
    }

};

TEST(testGameOfLife_8x4, emptyGrid)
{
	int expect = 0;
	gol_setAlive(4, 1);
	int result = gol_countAlives(4, 1);
	LONGS_EQUAL(expect, result);
}

TEST(testGameOfLife_8x4, oneCell)
{
	int expect = 1;
	gol_setAlive(4, 1);
	gol_setAlive(3, 0);
	int result = gol_countAlives(4, 1);
	LONGS_EQUAL(expect, result);
}

TEST(testGameOfLife_8x4, twoCells)
{
	int expect = 2;
	gol_setAlive(4, 1);
	gol_setAlive(3, 0);
	gol_setAlive(4, 0);
	int result = gol_countAlives(4, 1);
	LONGS_EQUAL(expect, result);
}

TEST(testGameOfLife_8x4, threeCells)
{
	int expect = 3;
	gol_setAlive(4, 1);
	gol_setAlive(3, 0);
	gol_setAlive(4, 0);
	gol_setAlive(5, 0);
	int result = gol_countAlives(4, 1);
	LONGS_EQUAL(expect, result);
}

TEST(testGameOfLife_8x4, fourCells)
{
	int expect = 4;
	gol_setAlive(4, 1);
	gol_setAlive(3, 0);
	gol_setAlive(4, 0);
	gol_setAlive(5, 0);
	gol_setAlive(3, 1);
	int result = gol_countAlives(4, 1);
	LONGS_EQUAL(expect, result);
}

TEST(testGameOfLife_8x4, fiveCells)
{
	int expect = 5;
	gol_setAlive(4, 1);
	gol_setAlive(3, 0);
	gol_setAlive(4, 0);
	gol_setAlive(5, 0);
	gol_setAlive(3, 1);
	gol_setAlive(5, 1);
	int result = gol_countAlives(4, 1);
	LONGS_EQUAL(expect, result);
}

TEST(testGameOfLife_8x4, sixCells)
{
	int expect = 6;
	gol_setAlive(4, 1);
	gol_setAlive(3, 0);
	gol_setAlive(4, 0);
	gol_setAlive(5, 0);
	gol_setAlive(3, 1);
	gol_setAlive(5, 1);
	gol_setAlive(3, 2);
	int result = gol_countAlives(4, 1);
	LONGS_EQUAL(expect, result);
}

TEST(testGameOfLife_8x4, sevenCells)
{
	int expect = 7;
	gol_setAlive(4, 1);
	gol_setAlive(3, 0);
	gol_setAlive(4, 0);
	gol_setAlive(5, 0);
	gol_setAlive(3, 1);
	gol_setAlive(5, 1);
	gol_setAlive(3, 2);
	gol_setAlive(4, 2);
	int result = gol_countAlives(4, 1);
	LONGS_EQUAL(expect, result);
}

TEST(testGameOfLife_8x4, eightCells)
{
	int expect = 8;
	gol_setAlive(4, 1);
	gol_setAlive(3, 0);
	gol_setAlive(4, 0);
	gol_setAlive(5, 0);
	gol_setAlive(3, 1);
	gol_setAlive(5, 1);
	gol_setAlive(3, 2);
	gol_setAlive(4, 2);
	gol_setAlive(5, 2);
	int result = gol_countAlives(4, 1);
	LONGS_EQUAL(expect, result);
}

TEST(testGameOfLife_8x4, leftTopCell)
{
	int expect = 3;
	gol_setAlive(0, 0);
	gol_setAlive(1, 0);
	gol_setAlive(0, 1);
	gol_setAlive(1, 1);
	int result = gol_countAlives(0, 0);
	LONGS_EQUAL(expect, result);
}

TEST(testGameOfLife_8x4, rightBottomCell)
{
	int expect = 3;
	gol_setAlive(7, 3);
	gol_setAlive(7, 2);
	gol_setAlive(6, 2);
	gol_setAlive(6, 3);
	int result = gol_countAlives(7, 3);
	LONGS_EQUAL(expect, result);
}

TEST(testGameOfLife_8x4, cellDeathRule)
{
	gol_setAlive(1, 1);
	gol_setAlive(2, 1);

	gol_nextGeneration();
	CHECK_FALSE(gol_isAlive(1, 1));
	CHECK_FALSE(gol_isAlive(2, 1));
}
