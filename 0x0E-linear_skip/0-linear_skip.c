#include "search.h"

/**
 * linear_skip - s
 * @list: p
 * @value: v
 *
 * Return: v
**/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *sk, *prev;

	if (!list)
	{
		return (NULL);
	}

	sk = list->express;
	prev = list;
	while (sk)
	{
		printf("Value checked at index [%lu] = [%d]\n", sk->index, sk->n);
		if (!sk->express || sk->n >= value)
		{
			if (sk->n < value && !sk->express)
			{
				prev = sk;
				while (sk->next)
					sk = sk->next;
			}
			printf("Value found between indexes [%lu] and [%lu]\n", prev->index,
				sk->index);
			while (prev)
			{
				printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
				if (prev->n > value)
					return (NULL);
				if (prev->n == value)
					return (prev);
				prev = prev->next;
			}
			break;
		}
		prev = sk;
		sk = sk->express;
	}
	return (NULL);
}
