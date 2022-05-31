#include "binary_trees.h"

/**
* heap_insert -  -
*
* @root: root
* @value: value
*
* Return: -
*/
heap_t *heap_insert(heap_t **root, int value)
{
	size_t idx, temp;
	size_t lve = 0;
	heap_t *node = NULL;

	if (*root == NULL)
	{
		*root = binary_tree_node((binary_tree_t *) *root, value);
		return (*root);
	}
	lve = ht_val(*root);
	for (idx = 0; idx <= lve; idx++)
	{
		node = (heap_t *) nd_ins((binary_tree_t *) *root, idx, value);
		if (node)
		{
			break;
		}
	}
	while (node->parent != NULL && node->n > node->parent->n)
	{
		temp = node->parent->n;
		node->parent->n = node->n;
		node->n = temp;
		node = node->parent;
	}
	return (node);
}

/**
* ht_val - tree
*
* @tree: tree
*
* Return: height
*/
size_t ht_val(const binary_tree_t *tree)
{
	int lh_val;
	int lr_val;

	if (!tree)
		return (0);
	if (aux_lf(tree) == 1)
		return (0);

	lr_val = ht_val(tree->right);
	lh_val = ht_val(tree->left);

	if (lh_val >= lr_val)
	{
		return (1 + lh_val);
	}
	return (1 + lr_val);
}

/**
* aux_lf - -
*
* @node: node
*
* Return: -
*/
int aux_lf(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (node->left == NULL && node->right == NULL)
	{
		return (1);
	}
	return (0);
}

/**
* nd_ins - -
*
* @tree: -
* @level: -
* @value: -
*
* Return: -
*/
binary_tree_t *nd_ins(binary_tree_t *tree, size_t level, int value)
{
	binary_tree_t *left, *right;

	if (!tree)
	{
		return (NULL);
	}
	if (ck_dp(tree) == level)
	{
		if (aux_lf(tree))
		{
			return (tree->left = binary_tree_node(tree, value));
		}
		if (tree->left != NULL && tree->right == NULL)
		{
			return (tree->right = binary_tree_node(tree, value));
		}
		return (NULL);
	}
	left = nd_ins(tree->left, level, value);
	if (left == NULL)
	{
		right = nd_ins(tree->right, level, value);
	}
	else
		return (left);
	return (right);
}

/**
* ck_dp -  chk
*
* @tree: -
*
* Return: -
*/
size_t ck_dp(const binary_tree_t *tree)
{
	int i = 0;

	if (tree == NULL)
	{
		return (0);
	}
	while (tree->parent != NULL)
	{
		i++;
		tree = tree->parent;
	}
	return (i);
}
