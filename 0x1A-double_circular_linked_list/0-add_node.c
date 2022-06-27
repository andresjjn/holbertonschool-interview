#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 *
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *node;
	char *strN;

	if (!list)
	{
		return (NULL);
	}

	node = malloc(sizeof(List));
	if (!node)
	{
		return (NULL);
	}

	strN = strdup(str);
	if (!strN)
	{
		free(node);
		return (NULL);
	}
	node->str = strN;

	if (!*list)
	{
		node->next = node;
		node->prev = node;
		*list = node;
		return (node);
	}

	node->next = *list;
	node->prev = (*list)->prev;

	(*list)->prev = node;
	node->prev->next = node;

	return (node);
}
/**
 * add_node_begin - Add a new node to the end of a double circular linked list
 *
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *node;
	char *strN;

	if (!list)
	{
		return (NULL);
	}

	node = malloc(sizeof(List));
	if (!node)
		return (NULL);

	strN = strdup(str);
	if (!strN)
	{
		free(node);
		return (NULL);
	}
	node->str = strN;

	if (*list)
	{
		node->next = *list;
		node->prev = (*list)->prev;
		(*list)->prev = node;
		if (node->prev)
		{
			node->prev->next = node;
		}
	}
	else
	{
		node->prev = node;
		node->next = node;
	}

	*list = node;

	return (node);
}
