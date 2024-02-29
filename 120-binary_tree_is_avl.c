#include "binary_trees.h"
#include <limits.h>

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
  * height - Measures the height of a binary tree.
  * @tree: A pointer to the root node of the node of the tree to measure
  *
  * Return: 0 if a tree is NULL, else must return height
  */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t i = 0, j = 0;

		i = tree->left ? 1 + height(tree->left) : 1;
		j = tree->right ? 1 + height(tree->right) : 1;
		return ((i > j) ? i : j);
	}
	return (0);
}

/**
  * is_avl_helper - Checks if a binary tree is a valid AVL Tree
  * @tree: A pointer to the root node of the tree to check
  * @lo: The value of the smallest node visited
  * @hi: The value of the highest node visited
  *
  * Return: 1 if the tree is a valid AVL Tree, otherwise 0
  */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t tmp, rec, temp;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		tmp = height(tree->left);
		rec = height(tree->right);
		temp = tmp > rec ? tmp - rec : rec - tmp;
		if (temp > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
				is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
  * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
  * @@tree: A pointer to the root node of the tree to check
  * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
  */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
