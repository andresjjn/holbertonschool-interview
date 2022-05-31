#include "menger.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * menger - draws a 2D Menger Sponge
 * @level: dpt
 */
void menger(int level)
{
	int a, b, c, d;
	int asd = 1, dpt;

	if (level < 0)
		return;

	dpt = pow(3, level);

	for (a = 1; a <= dpt; a++)
	{
		for (b = 1; b <= dpt; b++)
		{
			d = a - 1;
			c = b - 1;
			while (asd)
			{
				if (c == 0 || d == 0)
				{
					printf("#");
					break;
				}
				if (c % 3 == 1 && d % 3 == 1)
				{
					printf(" ");
					break;
				}
				c /= 3;
				d /= 3;
			}
		}
		printf("\n");
	}
}
