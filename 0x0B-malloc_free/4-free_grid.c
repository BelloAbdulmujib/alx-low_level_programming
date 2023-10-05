#include "main.h"

/**
 * free_grid - free 2 dimentional arrays
 * @grid: 2 dimentional grid
 * @height: the dimention of grid height
 * Return: nothig
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
