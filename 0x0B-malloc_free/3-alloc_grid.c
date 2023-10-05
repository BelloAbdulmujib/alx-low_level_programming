#include "main.h"
/**
 * alloc_grid - nested loop to make a grid
 * @width: input of width
 * @height: input of height
 * Return: pointers to 2 dim array
 */
int **alloc_grid(int width, int height)
{
	int **dee;
	int p, q;

	if (width <= 0 || i <= 0)
		return (NULL);

	dee = malloc(sizeof(int *) * height);

	if (dee == NULL)
		return (NULL);

	for (p = 0; p <= height; p++)
	{
		dee[p] = malloc(sizeof(int) * width)

		if (dee[p] == NULL)
		{
			for (; p >= 0; p--)
				free(dee[p]);

			free(dee);
			return (NULL);
		}
	}

	for (p = 0; p < height; p++)
	{
		for (q = 0; q < width; q++)
			dee[p][q] = 0;
	}
	return (dee);
}
