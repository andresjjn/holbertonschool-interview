#include "regex.h"

/**
 * regex_match - regex
 * @str: str
 * @pattern: pattern
 *
 * Return: match
 */
int regex_match(char const *str, char const *pattern)
{
	int fst_d = 0;
	int valid = 0;

	if (!str)
	{
		return (0);
	}

	if (!pattern)
	{
		return (0);
	};

	valid = *(pattern + 1) == '*';
	fst_d = *str && (*pattern == '.' || *str == *pattern);

	if (!*str && !valid)
	{
		return (*pattern ? 0 : 1);
	}

	if (fst_d && valid)
	{
		return (regex_match(str, pattern + 2) || regex_match(str + 1, pattern));
	}
	else if (valid)
	{
		return (regex_match(str, pattern + 2));
	}
	else if (fst_d && !valid)
	{
		return (regex_match(str + 1, pattern + 1));
	}

	return (0);
}
