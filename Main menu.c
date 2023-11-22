#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Title();
void MainMenu();
void Submenu();

int main() {
	MainMenu();
}

//Starts all necessary functions to display the Main Menu and other submenu's
void MainMenu() {
	int choice = 0;
	do {
		Title();	
		printf("\n\n");
		scanf("%d", &choice);
		
		switch (choice) {
		//Player presses Start
		case 1:
				Submenu();
				break;
		//Player exits
		case 2:
			exit(0);
		}
	} while (choice != 2);
}

//Displays logo and menu options
void Title() {
	printf("         ___ . .  _                                                                                             \n");
	printf("'T$$$P'   |  |_| |_                                                                                             \n");
	printf(" :$$$     |  | | |_                                                                                             \n");
	printf(" :$$$                                                      'T$$$$$$$b.                                          \n");
	printf(" :$$$     .g$$$$$p.   T$$$$b.    T$$$$$bp.                   BUG    'Tb      T$b      T$P   .g$P^^T$$  ,gP^^T$$ \n");
	printf("  $$$    d^'     '^b   $$  'Tb    $$    'Tb    .s^s. :sssp   $$$     :$; T$$P $^b.     $   dP'     `T :$P    `T \n");
	printf("  :$$   dP         Tb  $$   :$;   $$      Tb  d'   `b $      $$$     :$;  $$  $ `Tp    $  d$           Tbp.     \n");
	printf("  :$$  :$;         :$; $$   :$;   $$      :$; T.   .P $^^    $$$    .dP   $$  $   ^b.  $ :$;            'T$$p.  \n");
	printf("  $$$  :$;         :$; $$...dP    $$      :$;  `^s^' .$.     $$$...dP'    $$  $    `Tp $ :$;     'T$$      'T$b \n");
	printf("  $$$   Tb.       ,dP  $$'''Tb    $$      dP ''$''$' '$'$^^  $$$''T$b     $$  $      ^b$  T$       T$ ;      $$;\n");
	printf("  $$$    Tp._   _,gP   $$   `Tb.  $$    ,dP    $  $...$ $..  $$$   T$b    :$  $       `$   Tb.     :$ T.    ,dP \n");
	printf("  $$$;    '^$$$$$^'   d$$     `T.d$$$$$P^'     $  $'''$ $'', $$$    T$b  d$$bd$b      d$b   '^TbsssP' 'T$bgd$P  \n");
	printf("  $$$b.____.dP                                 $ .$. .$.$ss,d$$$b.   T$b.                                       \n");
	printf(".d$$$$$$$$$$P                                                                                                   \n");
	
	printf("\n\n\n");
	printf("1) Start\n");
	printf("2) Quit\n");
}

//When choosing start, the players will be met with 2 options, potentially
void Submenu() {
	int choice = 0;
	while (1) {
		printf("1) Solo\n");
		printf("2) Pass'n'Play\n");
		printf("3) Back\n");
		printf("\n\n");
		scanf("%d", &choice);
		switch (choice) {
		//Will send the player to fight against the AI
		case 1:
			break;
		//Will allow two players to play against eachother
		case 2:
			break;
		//Returns to the Main Menu
		case 3:
			MainMenu();
			break;
		}
	}
}

