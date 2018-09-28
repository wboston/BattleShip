
#include "Header.h"

// Pause function so i dont have to type this out every time
void pause(void) 
{
	printf("\n Press any key to continue... \n");
	system("pause");
}

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
		case 1:
			return 1;
		case 2:
			//print_Rules(); // TODO;
			pause();
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