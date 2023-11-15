#include <stdio.h>
#include <string.h>

//17 rows and 26 columns
//37    55

// Function declarations
void constructGrid();
void testAround();

// Variable/Constants declarations

int main() {
	char grid[37][55][1];
	int i, j;
	for ( i = 0; i < 37; i++)
	{
		for ( j = 0;  j < 55;  j++)
		{
			grid[i][j][0] = 32;
		}
	}	

	constructGrid(grid, 37, 55, 1);
	
	for (i = 0; i < 37; i++)
	{
		for (j = 0; j < 55; j++)
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
			// imprimir o resto das coordernadas (0 a 9) e grid
			else 
			{
				printf("%c", grid[i][j][0]);
			}
			
		}
		printf("\n");
	}

	return 0;
}

void constructGrid(char grid[37][55][1], int linha, int coluna, char valor) {
	int i, j;
	int ii = 0;
	int jj = 0;
	
	//coordernada vertical, 0 1 2...
	for ( i = 3, j = 0, ii =48; i < 37-1; i+=2)
	{
		grid[i][j][0] = ii;
		ii++;

		// a partir do 10 anulo a celua a sua frente, devido ao espaçamento
		if (i >= 23)
		{
			grid[i][1][0] = 0;
		}
	}

	//coordenadas horizontal, A B C....
	for ( j = 3, i = 0; j < 55; j+=2)
	{
		//printf("%c", 'A' + ii);
		grid[i][j][0] = 'A' + jj;
		jj++;
	}

	for (i = 2; i < linha; i++)
	{
		for (j = 2; j < coluna; j++)
		{
			if ((i % 2 == 1) && (j % 2 == 1) && (grid[i][j][0] = 32))
			{
				grid[i][j][0] = 32;
			}
			else
			{
				if (i % 2 == 0)
				{ // linha par
					if (i == 2) // primeira linha do grid
					{
						if (j % 2 == 1)
						{
							grid[i][j][0] = 196;
						}
						else
						{
							grid[i][j][0] = 194;
						}
					}
					else if (i == 36) // ultima linha do grid
					{
						if (j % 2 == 1)
						{
							grid[i][j][0] = 196;
						}
						else
						{
							grid[i][j][0] = 193;
						}
					}
					else
					{
						if (j % 2 == 1)
						{
							grid[i][j][0] = 196;
						}
						else
						{
							grid[i][j][0] = 197;
						}
					}
				}
				else
				{ //linha impar
					grid[i][j][0] = 179;
				}

				if (j == 2) // primeira coluna
				{
					if (i % 2 == 0) // apenas para alterar linhas entre duas celulas
					{
						grid[i][j][0] = 195;
					}					
				}
				else if (j == 54) // ultima coluna
				{
					if (i % 2 == 0) // apenas para alterar linhas entre duas celulas
					{
						grid[i][j][0] = 180;
					}
				}				
			}
		}
	}

	//cantos
	// superior esq
	grid[2][2][0] = 218;

	//superior drt
	grid[2][coluna - 1][0] = 191;

	//inferior esq
	grid[linha - 1][2][0] = 192;

	//inferior drt
	grid[linha - 1][coluna - 1][0] = 217;
}