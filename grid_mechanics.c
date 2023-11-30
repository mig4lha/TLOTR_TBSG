//grid_mechanics.c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include "grid_mechanics.h"  // Header file

char capitalizeChar(char c) {
    return (char)toupper((unsigned char)c);
}

int insertValueInMatrix(struct Matrix* grid, char value, int row, char column) {
    // Function to insert values into the game grid matrix
    value = capitalizeChar(value);

    int columnInt;

    columnInt = capitalizeChar(column) - 'A' + 1;

    if (grid->data[row - 1][columnInt - 1] != NULL) {
        return 0;
    }
    else {
        grid->data[row - 1][columnInt - 1] = value;
        return 1;
    }
    
}

void initializeGrid(struct Matrix* grid) {
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            grid->data[i][j] = NULL;
        }
    }
}

// Function definitions
void printGrid(struct Matrix grid) {

    // Print column indicators
    char letter;
    for (size_t i = 0; i < grid.cols; i++)
    {
        letter = 'A' + i;
        if (i == 0) {
            printf("%7c%c", 255, letter);
        }
        else if (i == grid.cols - 1) {
            printf("%3c%c\n", 255, letter);
        }
        else {
            printf("%3c%c", 255, letter);
        }

        //printf("%7cA   B   C   D   E   F   G   H   I   J   K   L   M   N   O   P   Q   R   S   T   U   V   W   X   Y   Z\n", 255);
    }
    

    // Accessing Matrix elements
    for (int lineCounter = 0; lineCounter <= grid.rows; lineCounter++) {
        for (int columnCounter = 0; columnCounter <= grid.cols; columnCounter++) {
            if (lineCounter == 0 && columnCounter == grid.cols) {
                printf("%c", 191);
            }
            else if (lineCounter == grid.rows && columnCounter == 0) {
                printf("%6c", 192);
                printf("%c", 196);
                printf("%c", 196);
                printf("%c", 196);
            }
            else if (lineCounter == grid.rows && columnCounter == grid.cols) {
                printf("%c", 217);
            }
            else if (lineCounter == 0 && columnCounter == 0) {
                printf("%6c", 218);
                printf("%c", 196);
                printf("%c", 196);
                printf("%c", 196);
            }
            else if (lineCounter == 0) {
                printf("%c", 194);
                printf("%c", 196);
                printf("%c", 196);
                printf("%c", 196);
            }
            else if (lineCounter == grid.rows) {
                printf("%c", 193);
                printf("%c", 196);
                printf("%c", 196);
                printf("%c", 196);
            }
            else if (columnCounter == grid.cols) {
                printf("%c", 180);
            }
            else if (columnCounter == 0) {
                printf("%6c", 195);
                printf("%c", 196);
                printf("%c", 196);
                printf("%c", 196);
            }
            else {
                printf("%c", 197);
                printf("%c", 196);
                printf("%c", 196);
                printf("%c", 196);
            }
        }
        printf("\n");
        if (lineCounter < grid.rows) {
            for (size_t i = 0; i < grid.cols; i++)
            {
                if (i == 0) {
                    lineCounter+1 < 10 ? printf("%c%i%3c", 255, lineCounter+1, 255) : printf("%c%i%2c", 255, lineCounter+1, 255);
                    printf("%c", 179); // Vertical line
                    printf("%c", 255);

                    // Print value here
                    if (grid.data[lineCounter][i] == NULL) {
                        printf("%c", 255);
                    }
                    else {
                        printf("%c", grid.data[lineCounter][i]);
                    }
                    // Print value here

                    printf("%c", 255); 
                }
                else if (i == grid.cols - 1) {
                    printf("%c", 179); // Vertical line
                    printf("%c", 255);

                    // Print value here
                    if (grid.data[lineCounter][i] == NULL) {
                        printf("%c", 255);
                    }
                    else {
                        printf("%c", grid.data[lineCounter][i]);
                    }
                    // Print value here

                    printf("%c", 255);
                    printf("%c", 179); // Vertical line
                }
                else {
                    printf("%c", 179); // Vertical line
                    printf("%c", 255);

                    // Print value here
                    if (grid.data[lineCounter][i] == NULL) {
                        printf("%c", 255);
                    }
                    else {
                        printf("%c", grid.data[lineCounter][i]);
                    }
                    // Print value here

                    printf("%c", 255);
                }    
            }
            printf("\n");
        }
    }
    printf("\n");
}