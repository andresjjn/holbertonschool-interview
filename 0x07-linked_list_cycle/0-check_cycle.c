#include "lists.h"

/**
* check_cycle - checks if a singly linked list has a cycle in it.
* @list: list to check
* Return: 0 if there is no cycle, 1 if there is a cycle
*/
int check_cycle(listint_t *list)
{
	if (!list)
	{
		return (0);
	}

	while (list)
	{
		if (list->next >= list)
		{
			return (1);
		}
		list = list->next;
	}
	return (0);
}
