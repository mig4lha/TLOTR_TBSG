#include <stdio.h>


// Function declarations
void constructGrid();
void testeVolta();

// Variable/Constants declarations

int main() {
	char grid[38][56][1];

	/*char t[1];

	t[0] = 218;

	if (t[0] != "")
	{
		printf("%c", t[0]);
	}*/


	//constructGrid(grid, 38, 56, 1);
	return 0;
}

void testeVolta(char grid[38][56][1], int linha, int coluna, char valor) {
	int i=0, j=0;
	//int i, j;

	//int teste[8] = {[] }

	if (grid[i][j][0] == "")
	{
		printf("calate");
	}
}

void constructGrid(char grid[38][56][1], int linha, int coluna, char valor) {
	int i, j = 0;

	for (i = 0; i < linha; i++)
	{
		if (j == 0)
		{
			grid[i][j][0] = j + 1;
		}

		for (j = 0; j < coluna; j++)
		{
			if (i == 0)
			{
				grid[i][j][0] = 'A' + j;
			}

		}
	}


	//cantos
	// superior esq
	grid[2][2][0] = 218;

	//superior drt
	grid[2][coluna][0] = 191;

	//inferior esq
	grid[linha][2][0] = 192;

	//inferior esq
	grid[linha][coluna][0] = 217;


	for (i = 3; i < linha; i += 2)
	{
		for (j = 3; j < coluna; j += 2)
		{

			testeVolta(grid, 38, 56, 1);


		}

	}
}