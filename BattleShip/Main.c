
#include "Header.h"

void main(void)
{
	int runGame = 1;
	runGame = Menu();

	char PlayerBoard[MAX_ROWS][MAX_COLS] = { '~' };		// Users playing board
	char CompBoard[MAX_ROWS][MAX_COLS] = { '~' };		// Computer Board

	while (runGame &&(runGame != -1))
	{

		initBoard(*PlayerBoard,'~');
		DispalyBoard(*PlayerBoard);
		// setup boards
		ManualPopulateBoard(PlayerBoard);

		// play

		// display results

		runGame = Menu();
	}
}