// main.c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "main.h"
#include "grid_mechanics.h"
#include "unit_building_management.h"

int main() {
	MainMenu();
    return 0;
}

//Displays logo and menu options
void Title() {
	printf("\n");
	printf("%2c         ___ . .  _                                                                                             \n", 255);
	printf("%2c'T$$$P'   |  |_| |_                                                                                             \n", 255);
	printf("%2c :$$$     |  | | |_                                                                                             \n", 255);
	printf("%2c :$$$                                                      'T$$$$$$$b.                                          \n", 255);
	printf("%2c :$$$     .g$$$$$p.   T$$$$b.    T$$$$$bp.                   BUG    'Tb      T$b      T$P   .g$P^^T$$  ,gP^^T$$ \n", 255);
	printf("%2c  $$$    d^'     '^b   $$  'Tb    $$    'Tb    .s^s. :sssp   $$$     :$; T$$P $^b.     $   dP'     `T :$P    `T \n", 255);
	printf("%2c  :$$   dP         Tb  $$   :$;   $$      Tb  d'   `b $      $$$     :$;  $$  $ `Tp    $  d$           Tbp.     \n", 255);
	printf("%2c  :$$  :$;         :$; $$   :$;   $$      :$; T.   .P $^^    $$$    .dP   $$  $   ^b.  $ :$;            'T$$p.  \n", 255);
	printf("%2c  $$$  :$;         :$; $$...dP    $$      :$;  `^s^' .$.     $$$...dP'    $$  $    `Tp $ :$;     'T$$      'T$b \n", 255);
	printf("%2c  $$$   Tb.       ,dP  $$'''Tb    $$      dP ''$''$' '$'$^^  $$$''T$b     $$  $      ^b$  T$       T$ ;      $$;\n", 255);
	printf("%2c  $$$    Tp._   _,gP   $$   `Tb.  $$    ,dP    $  $...$ $..  $$$   T$b    :$  $       `$   Tb.     :$ T.    ,dP \n", 255);
	printf("%2c  $$$;    '^$$$$$^'   d$$     `T.d$$$$$P^'     $  $'''$ $'', $$$    T$b  d$$bd$b      d$b   '^TbsssP' 'T$bgd$P  \n", 255);
	printf("%2c  $$$b.____.dP                                 $ .$. .$.$ss,d$$$b.   T$b.                                       \n", 255);
	printf("%2c.d$$$$$$$$$$P                                                                                                   \n", 255);

	printf("\n\n\n");
	printf("%2c1) Start\n", 255);
	printf("%2c2) Quit\n", 255);
}

//Starts all necessary functions to display the Main Menu and other submenu's
void MainMenu() {
	int choice = 0;
	do {
		Title();
		printf("\n\n");
		printf("%2cChoice: ", 255);
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			//Player presses Start
			Submenu();
			break;
		case 2:
			//Player exits
			exit(0);
		}
	} while (choice != 2);
}

//When choosing start, the players will be met with 2 options, potentially
void Submenu() {
	int choice = 0;
	while (1) {
		printf("\n\n%2c1) Solo\n", 255);
		printf("%2c2) Pass'n'Play\n", 255);
		printf("%2c3) Back\n", 255);
		printf("\n\n");
		printf("%2cChoice: ", 255);
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			//Will send the player to fight against the AI
			gameLoop();
			break;
		case 2:
			//Will allow two players to play against eachother
			gameLoop();
			break;
		case 3:
			//Returns to the Main Menu
			MainMenu();
			break;
		}
	}
}


// Implementation of the game loop
void gameLoop() {
    struct Matrix grid = { ROWS, COLS }; // <-- Adjust the size of the game grid

    // Accessing row and column information
    printf("\n\nGame Grid Information\n");
    printf("Rows: %d\n", grid.rows);
    printf("Cols: %d\n", grid.cols);
    printf("\n");

    initializeGrid(&grid);
    initializeAllUnitsAndBuildings();

    int flag = 1;

    while (flag != 0) {
		system("cls");
		printf("\n\n");
        printGrid(grid); // Initialize the game grid

        int row, check;
        char value, column;
		char quit[20];

        printf("\nChoose a value to place ('Quit' to go to the Main Menu): ");
        scanf("%s", &quit);
		if (strcmp(quit, "Quit") == 0) {
			system("cls");
			MainMenu();
		}
		else {
			value = quit[0];
		}

        printf("Choose coordinates for the unit (ex. A1): ");
        scanf(" %c", &column, 1);
        scanf("%i", &row);

        check = insertValueInMatrix(&grid, value, row, column);
        if (check == 0) {
            printf("\n -> Error: There is already a unit occupying that cell!\n");
        }

        printf("\n------------------------------------------------------------------------------------------------------------------\n\n");
    }

}

