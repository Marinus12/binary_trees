#include "binary_trees.h"

/**
 * height - height of a binary tree.
 * @tree: pointer to root.
 * Return: If tree is NULL, 0.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t x = 0, y = 0;

		x = tree->left ? 1 + height(tree->left) : 1;
		y = tree->right ? 1 + height(tree->right) : 1;

		return ((x > y) ? x : y);
	}

	return (0);
}
/**
 * binary_tree_balance - balance factor of a binary tree.
 * @tree: A pointer.
 * Return: 0 or height.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (height(tree->left) - height(tree->right));

	return (0);
}
