#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i:
	for (i = 0; i < argc; i++)
	{
		_putchar("%s ", argv[i]);
	}
	_putchar("\n");
}
