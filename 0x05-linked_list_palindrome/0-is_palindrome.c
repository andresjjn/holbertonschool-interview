#include "lists.h"

/**
 * is_palindrome - pal
 *
 * @head: head
 *
 * Return:	result
 */

int is_palindrome(listint_t **head)
{
	int strt, fnsh;
	int ar[100000];
	listint_t *nd;

	if (!head)
		return (1);

	nd = *head;

	if (!nd)
		return (1);

	strt = 0;

	for (fnsh = 0; nd; fnsh++)
	{
		ar[fnsh] = nd->n;
		nd = nd->next;
	}

	fnsh--;

	while (strt <= fnsh)
	{
		if (ar[strt] != ar[fnsh])
			return (0);
		strt++;
		fnsh--;
	}
	return (1);
}
