#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves.
 * @tree: the pointer.
 * Return: no of leaves.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t c = 0;

	if (tree)
	{
		c = c + (!tree->left && !tree->right) ? 1 : 0;
		c = c + binary_tree_leaves(tree->left);
		c = c + binary_tree_leaves(tree->right);
	}
	return (c);
}
