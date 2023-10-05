#include "main.h"
/**
 * free_grid - free 2 dimentional arrays
 * @grid: 2 dimentional grid
 * @height: the dimention of grid height
 * Return: nothig
 */
void free_grid(int **grid, int height)
{
	int k;

	for (k = 0; k < height; k++)
	{
		free(grid[k]);
	}
	free(grid);
}
