#pragma once
#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// custom helper type to make booleans easier
typedef enum bool
{
	FALSE, TRUE
}Bool;

typedef struct stat
{
	int Shots;
	int Misses;
	int Hits;
	int Hit_miss;
	char Win_Loss;
} Stat;

int length(char *str);
void pause(void);
int Menu(void);
void printRules(void);

void initBoard(char board[][MAX_COLS], char symbol);
void DispalyBoard(char board[][MAX_COLS]);
void PlaceShips(char *board[][MAX_COLS]);
void PlaceShip(char *board[][MAX_COLS], int Row, int Col, int direction, char ico);
int CheckPos(int Row, char Col, int Len, int direction);

void ManualPopulateBoard(char *board[][MAX_COLS]);
void AutoPopulateBoard(char *board[][MAX_COLS]);


#endif // !HEADER_H
