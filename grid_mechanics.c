#include <stdio.h>

// Function declarations
void inititializeGrid();
void insertValuesInGrid();

// Variable/Constants declarations

// Define the Matrix to be used to create the game grid
struct Matrix {
    int rows;
    int cols;
};

int main() {

    inititializeGrid(); // Initialize the game grid

    return 0;
}

void insertValuesInGrid() {

}

// Function definitions
void inititializeGrid() {
    struct Matrix grid = { 17, 26 }; // <-- Adjust the size of the game grid

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
        {"","","","","","","","","","","","","","","","","","","","","","","","","",""},
    };

    // Accessing row and column information
    printf("Game Grid Information\n");
    printf("Rows: %d\n", grid.rows);
    printf("Cols: %d\n", grid.cols);
    printf("\n");

    // Printing a square
    //printf("%4c", 218); // Upper-Left corner
    //printf("%c", 196); // Horizontal line
    //printf("%c", 196); // Horizontal line
    //printf("%c", 196); // Horizontal line
    //printf("%c", 191); // Upper-Right corner
    //printf("\n");
    //printf("%4c", 179); // Vertical line
    //printf("%4c", 179); // Vertical line
    //printf("\n");
    //printf("%4c", 192); // Lower-Left corner
    //printf("%c", 196); // Horizontal line
    //printf("%c", 196); // Horizontal line
    //printf("%c", 196); // Horizontal line
    //printf("%c", 217); // Lower-Right corner

    int counter = 1;

    // Accessing Matrix elements
    for (int lineCounter = 0; lineCounter <= grid.rows; lineCounter++) {
        for (int columnCounter = 0; columnCounter <= grid.cols; columnCounter++) {
            if (lineCounter == 0 && columnCounter == grid.cols) {
                printf("%c", 191);
            }
            else if (lineCounter == grid.rows && columnCounter == 0) {
                printf("%4c", 192);
                printf("%c", 196);
                printf("%c", 196);
                printf("%c", 196);
            }
            else if (lineCounter == grid.rows && columnCounter == grid.cols) {
                printf("%c", 217);
            }
            else if (lineCounter == 0 && columnCounter == 0) {
                printf("%4c", 218);
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
                printf("%4c", 195);
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
                    printf("%4c", 179); // Vertical line
                    printf("%c", 255);

                    // Print value here
                    if (testArray[lineCounter][i][1] == 0) {
                        printf("%c", 255);
                    }
                    else {
                        printf("%c", testArray[lineCounter][i][1]);
                    }
                    // Print value here

                    printf("%c", 255); 
                }
                else if (i == grid.cols - 1) {
                    printf("%c", 179); // Vertical line
                    printf("%c", 255);

                    // Print value here
                    if (testArray[lineCounter][i][1] == 0) {
                        printf("%c", 255);
                    }
                    else {
                        printf("%c", testArray[lineCounter][i][1]);
                    }
                    // Print value here

                    printf("%c", 255);
                    printf("%c", 179); // Vertical line
                }
                else {
                    printf("%c", 179); // Vertical line
                    printf("%c", 255);

                    // Print value here
                    if (testArray[lineCounter][i][1] == 0) {
                        printf("%c", 255);
                    }
                    else {
                        printf("%c", testArray[lineCounter][i][1]);
                    }
                    // Print value here

                    printf("%c", 255);
                }    
            }
            printf("\n");

        }
    }
}