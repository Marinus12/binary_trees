#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: some pointer
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t i = 0;

	if (tree)
	{
		i = i + 1;
		i = i + binary_tree_size(tree->left);
		i = i + binary_tree_size(tree->right);
	}
	return (i);
}

