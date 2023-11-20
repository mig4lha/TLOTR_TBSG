#include <stdio.h>

// Function declarations
void initializeGrid();
void insertValuesInGrid();

// Variable/Constants declarations

// Define the Matrix to be used to create the game grid
struct Matrix {
    int rows;
    int cols;
};

int main() {

    initializeGrid(); // Initialize the game grid

    return 0;
}

void insertValuesInGrid() {
    // Function to insert values into the game grid (currently empty)
}

// Function definitions
void initializeGrid() {
    struct Matrix grid = { 17, 26 }; // <-- Adjust the size of the game grid

    // Define the game grid with ASCII characters
    char testArray[17][26][1] = {
        {"","","","","","","","","","","","","","","","","","","","","","","","","",""},
        {"","","","","","","","","","","","","","","","","","","","","","","","","",""},
        {"","","","","","","","","","","","","","","","","","","","","","","","","",""},
        {"","","","","","","","","","","","","","","","","","","","","","","","","",""},
        {"","","","","","","S","E","N","D","","","","","","","","","","","","","","","",""},
        {"","","","","","","","","","","","","","","","","","","","","","","","","",""},
        {"","","","","","","","","","","","","H","E","L","P","","","","","","","","","",""},
        {"","","","","","","","","","","","","","","","","","","","","","","","","",""},
        {"","","","","","","","","","","","","","","","","","","P","L","E","A","S","E","",""},
        {"","","","","","","","","","","","","","","","","","","","","","","","","",""},
        {"","","","","","","","","","","","","","","","","","","","","","","","","",""},
        {"","","","","","","","","","","","","","","","","","","","","","","","","",""},
        {"","","","","","","","","","","","","","","","","","","","","","","","","",""},
        {"","","","","","","","","","","","","","","","","","","","","","","","","",""},
        {"","","","","","","","","","","","","","","","","","","","","","","","","",""},
        {"","","","","","","","","","","","","","","","","","","","","","","","","",""},
        {"","","","","","","","","","","","","","","","","","","","","","","A","A","A","A"},
    };

    // Accessing row and column information
    printf("Game Grid Information\n");
    printf("Rows: %d\n", grid.rows);
    printf("Cols: %d\n", grid.cols);
    printf("\n");

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
                    if (testArray[lineCounter][i][0] == 0) {
                        printf("%c", 255);
                    }
                    else {
                        printf("%c", testArray[lineCounter][i][0]);
                    }
                    // Print value here

                    printf("%c", 255); 
                }
                else if (i == grid.cols - 1) {
                    printf("%c", 179); // Vertical line
                    printf("%c", 255);

                    // Print value here
                    if (testArray[lineCounter][i][0] == 0) {
                        printf("%c", 255);
                    }
                    else {
                        printf("%c", testArray[lineCounter][i][0]);
                    }
                    // Print value here

                    printf("%c", 255);
                    printf("%c", 179); // Vertical line
                }
                else {
                    printf("%c", 179); // Vertical line
                    printf("%c", 255);

                    // Print value here
                    if (testArray[lineCounter][i][0] == 0) {
                        printf("%c", 255);
                    }
                    else {
                        printf("%c", testArray[lineCounter][i][0]);
                    }
                    // Print value here

                    printf("%c", 255);
                }    
            }
            printf("\n");

        }
    }
}