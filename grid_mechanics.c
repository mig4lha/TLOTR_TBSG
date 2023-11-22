#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

// Variable/Constants declarations
#define ROWS 17
#define COLS 26

// Function declarations
void printGrid(struct Matrix grid);
void initializeGrid(struct Matrix* grid);
int insertValueInMatrix(struct Matrix* grid, char value, int row, char column);

// Define the Matrix to be used to create the game grid
struct Matrix {
    int rows;
    int cols;
    char data[ROWS][COLS];
};

/*int main() {
    struct Matrix grid = { ROWS, COLS }; // <-- Adjust the size of the game grid
    initializeGrid(&grid);

    int flag = 1;

    // Accessing row and column information
    printf("Game Grid Information\n");
    printf("Rows: %d\n", grid.rows);
    printf("Cols: %d\n", grid.cols);
    printf("\n");

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

    return 0;
}*/

char capitalizeChar(char c) {
    return (char)toupper((unsigned char)c);
}

int letterToInt(char letter) {
    letter = capitalizeChar(letter);
    if (letter >= 'A' && letter <= 'Z') {
        return letter - 'A' + 1;
    }
}

char intToLetter(int position) {
    if (position >= 1 && position <= 26) {
        return 'A' + position - 1;
    }
}

int insertValueInMatrix(struct Matrix* grid, char value, int row, char column) {
    // Function to insert values into the game grid matrix
    value = capitalizeChar(value);

    int columnInt;

    columnInt = letterToInt(column);

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
        letter = intToLetter(i + 1);
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