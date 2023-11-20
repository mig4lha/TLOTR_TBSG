#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Function declarations
void printGrid(struct Matrix grid);
void initializeGrid(struct Matrix* grid);
void insertValueInMatrix(struct Matrix* grid, char value, int row, int column);

// Variable/Constants declarations

// Define the Matrix to be used to create the game grid
struct Matrix {
    int rows;
    int cols;
    char data[17][26];
};

int main() {
    struct Matrix grid = { 17, 26 }; // <-- Adjust the size of the game grid
    initializeGrid(&grid);

    int flag = 1;

    // Accessing row and column information
    printf("Game Grid Information\n");
    printf("Rows: %d\n", grid.rows);
    printf("Cols: %d\n", grid.cols);
    printf("\n");

    while (flag != 0) {
        printGrid(grid); // Initialize the game grid

        int row, column;
        char value;
        printf("\nChoose a value to insert: ");
        scanf(" %c", &value);
        printf("Row number: ");
        scanf("%i", &row);
        printf("Column number: ");
        scanf("%i", &column);

        insertValueInMatrix(&grid, value, row, column);

        printf("\n------------------------------------------------------------------------------------------------------------------\n\n");
    }

    return 0;
}

void insertValueInMatrix(struct Matrix* grid, char value, int row, int column) {
    // Function to insert values into the game grid matrix
    grid->data[row-1][column-1] = value;
}

void initializeGrid(struct Matrix* grid) {
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            grid->data[i][j] = 0;
        }
    }
}

// Function definitions
void printGrid(struct Matrix grid) {

    // Print column indicators
    printf("%7cA   B   C   D   E   F   G   H   I   J   K   L   M   N   O   P   Q   R   S   T   U   V   W   X   Y   Z\n", 255);

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
                    if (grid.data[lineCounter][i] == 0) {
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
                    if (grid.data[lineCounter][i] == 0) {
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
                    if (grid.data[lineCounter][i] == 0) {
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