#include <stdio.h>
#include <string.h>

//17 rows and 26 columns
//37    53

// Function declarations
void constructGrid();
void testAround();

// Variable/Constants declarations

int main() {
	char grid[37][53][1];
	int i, j;
	for ( i = 0; i < 37; i++)
	{
		for ( j = 0;  j < 53;  j++)
		{
			grid[i][j][0] = 32;
		}
	}

	/*char t[8] = {
		[-1, -1]
	};*/


	//t[0] = 218;

	/*if (t[0] != "")
	{
		printf("%c", t[0]);
	}*/

	/*int AROUND_CELL_OPERATORS[8][2] = {
		{-1, -1},
		{-1, 0},
		{-1, 1},
		{0, -1},
		{0, 1},
		{1, -1},
		{1, 0},
		{1, 1}
	};

	int num_operators = sizeof(AROUND_CELL_OPERATORS) / sizeof(AROUND_CELL_OPERATORS[0]);

	printf("%d", num_operators);*/

	

	constructGrid(grid, 37, 53, 1);
	
	for (i = 0; i < 37; i++)
	{
		for (j = 0; j < 53; j++)
		{
			// é para imprimir os valores de 10 a 16 nas coordenadas
			if (grid[i][j][0] > '9' && grid[i][j][0] < 'A')
			{
				printf("%d", i/2 -1);
			}
			// é para imprimir as letras de A a Z nas coordenadas
			else if (grid[i][j][0] >= 'A' && grid[i][j][0] <= 'Z')
			{
				printf("%c", grid[i][j][0]);
			}
			// imprimir o resto das coordernadas e grid
			else 
			{
				printf("%c", grid[i][j][0]);
			}
			
		}
		printf("\n");
	}

	/*for ( i = 20; i < 34; i+=2)
	{
		grid[i][0][0] = i;
		printf("%c", grid[i][0][0]);
	}*/

	return 0;
}

void testAround(char grid[37][53][1], int x, int y, char valor) {
	/* pre view of around cell operators
	{
		{-1, -1}, {-1, 0}, {-1, 1},
		{0, -1},           {0, 1},
		{1, -1}, {1, 0}, {1, 1}
	};
	*/
	int AROUND_CELL_OPERATORS[8][2] = {
		{-1, -1},
		{-1, 0},
		{-1, 1},
		{0, -1},
		{0, 1},
		{1, -1},
		{1, 0},
		{1, 1}
	};

	int i, j=0;

	int num_rows = sizeof(AROUND_CELL_OPERATORS) / sizeof(AROUND_CELL_OPERATORS[0]);

	for ( i = 0; i < num_rows; i++)
	{
		if (grid[x][y][0] == 0)
		{
			printf("calate");
		}
	}

	
}

void constructGrid(char grid[37][53][1], int linha, int coluna, char valor) {
	int i, j;
	int ii = 0;
	int jj = 0;

	for ( i = 4, j = 0, ii =48; i < 37-2; i+=2)
	{
		grid[i][j][0] = ii;
		ii++;
	}

	//coordenadas horizontal, A B C....
	for ( j = 4, i = 0; j < 53-2; j+=2)
	{
		//printf("%c", 'A' + ii);
		grid[i][j][0] = 'A' + jj;
		jj++;
	}

	

	//cantos
	// superior esq
	grid[3][3][0] = 218;

	//superior drt
	grid[3][coluna-1][0] = 191;

	//inferior esq
	grid[linha-1][3][0] = 192;

	//inferior esq
	grid[linha-1][coluna-1][0] = 217;

	for (i = 4; i < linha; i += 2)
	{
		for (j = 4; j < coluna; j += 2)
		{
			// manda as coordenadas da celula vazia, e faz o teste a sua volta 
			testAround(grid, i, j, 1);


		}

	}
}