#include <stdlib.h>
#include "dog.h"

/**
 * int_dog - function that initialize a variable of type struct dog
 * @d: struct of dog
 * @name: name of dog
 * @age: age of dog
 * @owner: dog owner's name
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
