#include "lists.h"
#include <stdlib.h>

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: pointer to the node where the loop start, or NULL if there is no loop
 * Return: loop pointer or null
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *a, *b;

	a = head;
	b = a;

	while (a && b && b->next)
	{
		b = b->next->next;
		a = a->next;
		if (a == b)
		{
			a = head;
			while (a && b)
			{
				if (a == b)
				{
					return (a);
				}
				b = b->next;
				a = a->next;
			}
		}
	}
	return (NULL);
}
