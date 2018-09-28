#pragma once
#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

// custom helper type to make booleans easier
typedef enum bool
{
	FALSE, TRUE
}Bool;

void pause(void);
int Menu(void);
void printRules(void);


#endif // !HEADER_H
