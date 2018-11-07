
#include "Header.h"

// i didn't want to type this out every time...

void pause(void) 
{
	system("pause");
}

// Menu: Displays the welcome Menu and handles users selection
int Menu(void)
{
	int MenuSelection = 0;

	while (TRUE)
	{
		printf("- Welcome to Battleship -\n");
		printf("1. Play Game\n");
		printf("2. Game Rules\n");
		printf("3. Quit/End\n");
		printf("type a number from above to select that menu item\n>>");
		scanf("%d", &MenuSelection);
		system("cls");

		switch (MenuSelection)
		{
		case 1:			// user wants to play
			return 1;
		case 2:
			printRules(); // TODO;
			break;
		case 3:
			return -1;
		default:
			system("cls");
			printf("\n!- UnRecognized Input -- Please try again -!\n\n");
			fseek(stdin, 0, SEEK_END);	// clearing stdin of any extra                                                        characters
			break;
		}
	}
}

void printRules(void)
{
	system("cls");
	printf("- BattleShip Rules -\n");
	printf("yeah... its battleship.\nThe oponnent is a computer so good luck!\n\n");
	pause();
	system("cls");
}

void initBoard(char board[][MAX_COLS],char symbol)
{
	int x, y = 0; // iterator initalization

	for (x = 0; x < MAX_ROWS; x++)
	{
		for (y = 0; y < MAX_COLS; y++) 
		{
			board[x][y] = symbol;
		}
	}

}

void DispalyBoard(char board[][MAX_COLS])
{
	int x = 0, y = 0; // iterator initalization
	printf("  A B C D E F G H I J\n");

	for (y = 0; y < MAX_COLS; y++)
	{
		printf("%d ", y + 1);
		for (x = 0; x < MAX_ROWS; x++)
		{
			printf("%c ", board[x][y]);
		}
		printf("\n");
	}
}

void PlaceShips(char *board[][MAX_COLS])
{
	int input = 0;
	while ((input != 1) && (input != 2))
	{
		system("cls");
		printf("To get started, do you want to:\n1. manually place your ships\nor\n2. Have them randomly place for you?\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			// manually place ships
			//populareBoard(board);
			break;
		case 2:
			// Random and automatically
			break;
		default:
			printf("\n!- UnRecognized Input -- Please try again -!\n\n");
			fseek(stdin, 0, SEEK_END);	// clearing stdin of any extra 
			break;
		}
	}

	// Populate Computers board...
}

void PlaceShip(char **board[][MAX_COLS],int Row, int Col, int Direction, int Length, char ico)
{
	int i = 0;
	for (i = 0; i < Length; i++) {
		if (Direction == 0) {
			*board[Row + i][Col] == ico;
		}
		if (Direction == 1) {
			*board[Row][Col + i] == ico;
		}
	}
}

int CheckPos(int Row, char Col, int Len, int direction)
{
	int result = (int)Col;
	if ((result >= 65) && (result <= 90)) {( result -= 65); } // if its uppercase
	else if ((result >= 97) && (result <= 122)) { (result -= 97); } // if its lowercase
	else // invalid Col Start
	{
		return -1;
	}

	if (((Row < 1) || (Row > 10)))
	{
		return -1; // invalid row start
	}

	if (direction == 1) // place horizontally
	{
		if ((Row + Len) > 10) { return -1; }
	}
	if (direction == 0) // place Vertically
	{
		if ((result + Len) > 10) { return -1; }
	}

	return result; // good placement
}

void ManualPopulateBoard(char *board[][MAX_COLS])
{
	const char ship_types[5][15] = { "carrier", "battleship", "cruiser", "submarine", "destroyer" };
	int shipLength[5] = { 5,4,3,3,2 };
	char shipChar[5] = { 'C','B','R','S','D'};


	for (int i = 0; i < 5; i++) 
	{
		system("cls");
		DispalyBoard(board);

		int row = 0;
		char col = "A";
		int numCol = 0;
		int direction = 0;
		fseek(stdin, 0, SEEK_END);	// clearing stdin of any extra 

		do {
			printf("Where do you want to place your %s\n it is %d spaces long\n Example input: [1A]->(row, column)\n>>", ship_types[i], shipLength[i]);
			scanf("\n%d%c", &row, &col);
			//
			printf("Which direction do you want to place the ship:\n[1] Down \n[2] Right\n");
			scanf("%d", &direction);
			
			row--; // because the array is base 0
			numCol = CheckPos(row, col, shipLength[i], direction);
		} while (numCol == -1); // check for good input


		PlaceShip(board, row, numCol, direction, shipLength[i], shipChar[i]);
		
		// Repeat
	}
}

void AutoPopulateBoard(char *board[][MAX_COLS])
{

}



void play(void)
{

}