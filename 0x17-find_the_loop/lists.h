#ifndef lists_header
#define lists_header

#include <stdlib.h>

/**
 * struct listint_s - listint
 * @n: integer
 * @next: points to the next node
 *
 * Description: list
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;
listint_t *find_listint_loop(listint_t *head);
listint_t *add_nodeint(listint_t **head, const int n);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);

#endif
