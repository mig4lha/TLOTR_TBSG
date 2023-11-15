#include <stdio.h>

// Function declarations
void inititializeGrid();

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

// Function definitions
void inititializeGrid() {
    struct Matrix grid = { 17, 26 }; // <-- Adjust the size of the game grid

    // Accessing row and column information
    printf("Game Grid Information\n");
    printf("Rows: %d\n", grid.rows);
    printf("Cols: %d\n", grid.cols);
    printf("\n");

    // Accessing Matrix elements
    for (int lineCounter = 0; lineCounter < grid.rows; lineCounter++) {
        for (int columnCounter = 0; columnCounter < grid.cols; columnCounter++) {
            if (lineCounter == 0 && columnCounter == 25) {
                printf("%c", 191);
            }
            else if (lineCounter == 16 && columnCounter == 0) {
                printf("%4c", 192);
                printf("%c", 196);
                printf("%c", 196);
                printf("%c", 196);
            }
            else if (lineCounter == 16 && columnCounter == 25) {
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
            else if (lineCounter == 16) {
                printf("%c", 193);
                printf("%c", 196);
                printf("%c", 196);
                printf("%c", 196);
            }
            else if (columnCounter == 25) {
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
    }
}