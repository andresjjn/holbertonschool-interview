#include "binary_trees.h"

/**
 * binary_tree_is_avl - f
 * @tree: tree
 * Return: response
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int h = 0;
	int res = NULL;

	if (!tree)
	{
		return (0);
	}
	res = tree_validation(tree, INT_MIN, INT_MAX, &h);
	return (res);
}

/**
 * tree_validation - f
 * @node: node to validate
 * @min: min int
 * @max: max int
 * @h: tree height
 * Return: response
 */

int tree_validation(const binary_tree_t *node, int min, int max, int *h)
{
	int le = 0;
	int ri = 0;
	int res = NULL;

	if (!node)
	{
		return (1);
	}

	if (node->n >= max)
	{
		return (0);
	}

	if (node->n <= min)
	{
		return (0);
	}

	if (!tree_validation(node->left, min, node->n, &le))
	{
		return (0);
	}

	if (!tree_validation(node->right, node->n, max, &ri))
	{
		return (0);
	}

	*h = (le > ri ? le : ri) + 1;
	res = abs(le - ri) < 2;
	return (res);
}
