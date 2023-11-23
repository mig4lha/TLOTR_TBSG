// grid_mechanics.h
#ifndef GRID_MECHANICS_H
#define GRID_MECHANICS_H

// Variable/Constants declarations
#define ROWS 3
#define COLS 3

// Define the Matrix to be used to create the game grid
struct Matrix {
    int rows;
    int cols;
    char data[ROWS][COLS];
};

// Function declarations
void printGrid(struct Matrix grid);
void initializeGrid(struct Matrix* grid);
int insertValueInMatrix(struct Matrix* grid, char value, int row, char column);

#endif
