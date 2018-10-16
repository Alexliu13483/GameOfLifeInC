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
	int result = gol_countAlive();
	LONGS_EQUAL(expect, result);
}

TEST(testGameOfLife_8x4, oneCell)
{
	int expect = 1;
	gol_setCell(4, 1);
	int result = gol_countAlive();
	LONGS_EQUAL(expect, result);
}
