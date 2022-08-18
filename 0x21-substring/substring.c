#include "substring.h"

/**
 * find_substring - find substring
 * @s: str
 * @words:  words
 * @nb_words: nb words
 * @n: n
 *
 * Return: return
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i, x, y;
	int idx, acm, lstr, lwrd, cstr;
	int *arr_id, *mchd;

	if (!s || !words || !n || nb_words == 0)
		return (NULL);

	lstr = strlen(s);
	lwrd = strlen(words[0]);
	arr_id = malloc(lstr * sizeof(int));
	if (!arr_id)
		return (NULL);
	mchd = malloc(nb_words * sizeof(int));
	if (!mchd)
		return (NULL);
	for (i = acm = 0; i <= lstr - nb_words * lwrd; i++)
	{
		memset(mchd, 0, nb_words * sizeof(int));
		for (x = 0; x < nb_words; x++)
		{
			for (y = 0; y < nb_words; y++)
			{
				idx = i + x * lwrd;
				cstr = strncmp(s + idx, *(words + y), lwrd);
				if (!*(mchd + y) && !cstr)
				{
					*(mchd + y) = 1;
					break;
				}
			}
			if (y == nb_words)
				break;
		}
		if (x == nb_words)
			*(arr_id + acm) = i, acm += 1;
	}
	free(mchd);
	*n = acm;
	return (arr_id);
}
