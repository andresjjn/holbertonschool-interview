#include "holberton.h"
#include <stdio.h>

/**
 * wildcmp - compares two string
 * @s1: string 1
 * @s2: string 1
 * Return: 1 if the strings can be considered identical, otherwise 0.
 */
int wildcmp(char *s1, char *s2)
{
	if (!*s1)
	{
		if (*s2 == '*')
		{
			return (wildcmp(s1, s2 + 1));
		}
		return (!*s2);
	}
	if (*s2 == '*')
	{
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	}
	if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}
	return (0);
}
