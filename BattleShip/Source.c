
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
			printf("!- UnRecognized Input -- Please try again -!");
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

