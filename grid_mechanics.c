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

    int counter = 1;

    // Accessing matrix elements
    for (int i = 0; i < grid.rows; i++) {
        for (int j = 0; j < grid.cols; j++) {
            printf("%4d ", counter);
            counter++;
        }
        printf("\n");
    }
}
