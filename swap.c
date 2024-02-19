#include "sort.h"

/**
 * swap - swaping elements
 * @xp: input
 * @yp: input
 * Return: void
*/

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
