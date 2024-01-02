// main.h
#ifndef MAIN_H
#define MAIN_H

// Function declarations
void gameLoop();
void MainMenu();
void Title();
void Submenu();
void placeUnitBuilding(struct Matrix* grid);
void handleAction(struct Player* currentPlayer, int action, struct Matrix* grid);

// Global variables if needed

#endif
