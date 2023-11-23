// main.c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "main.h"
#include "grid_mechanics.h"
#include "unit_building_management.h"

int main() {
    gameLoop();
    return 0;
}

// Implementation of the game loop
void gameLoop() {
    struct Matrix grid = { ROWS, COLS }; // <-- Adjust the size of the game grid

    // Accessing row and column information
    printf("Game Grid Information\n");
    printf("Rows: %d\n", grid.rows);
    printf("Cols: %d\n", grid.cols);
    printf("\n");

    initializeGrid(&grid);
    initializeAllUnitsAndBuildings();

    int flag = 1;

    while (flag != 0) {
        printGrid(grid); // Initialize the game grid

        int row, check;
        char value, column;
        printf("\nChoose a value to place: ");
        scanf(" %c", &value);
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

