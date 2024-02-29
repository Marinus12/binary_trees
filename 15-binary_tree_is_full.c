#include "binary_trees.h"

/**
 * is_full - is full checking.
 * @tree: A pointer.
 * Return: 0 or 1
 */
int is_full(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    is_full(tree->left) == 0 ||
		    is_full(tree->right) == 0)
			return (0);
	}

	return (1);
}

/**
 * binary_tree_is_full - Checks if tree is full.
 * @tree: A pointer.
 * Return: -0 0r -1.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_full(tree));
}

