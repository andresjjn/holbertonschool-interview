#include "lists.h"

/**
 * insert_node - inset node
 * @head: head
 *
 * @number: num
 *
 * Return: -
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *varaux, *nd;

	if (head == NULL)
		return (NULL);

	varaux = *head;
	nd = malloc(sizeof(listint_t));

	if (nd == NULL)
		return (NULL);

	nd->n = number;
	nd->next = NULL;

	if (varaux == NULL || varaux->n > number)
	{
		nd->next = *head;
		*head = nd;
		return (nd);
	}
	while (varaux)
	{
		if (varaux->next != NULL)
		{
			if (varaux->next->n > number)
			{
				nd->next = varaux->next;
				varaux->next = nd;
				return (nd);
			}
			varaux = varaux->next;
		} else
		{
			nd->next = NULL;
			varaux->next = nd;
			return (nd);
		}
	}
	return (nd);
}
