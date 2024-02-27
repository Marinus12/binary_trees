#include "binary_trees.h"

/**
  * binary_tree_depth - Measures the depth of a node in a binary tree
  * @tree: Pointer to the node to measure the depth
  *
  * Return: 0 if tree is NULL
  */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t i = 0, k = 0;

		i = tree->left ? 1 + binary_tree_depth(tree->left) : 0;
		k = tree->right ? 1 + binary_tree_depth(tree->right) : 0;
		return ((i > k) ? i : k);
	}
	return (0);
}
