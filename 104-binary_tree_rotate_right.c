#include "binary_trees.h"

/**
  * binary_tree_rotate_right - Performs a right-rotation on a binary tree
  * @tree: A pointer to the root node of the tree to rotate
  *
  * Return: A pointer to the new root node of the tree once rotated
  */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *hinge, *tmp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	hinge = tree->left;
	tmp = hinge->right;
	hinge->right = tree;
	tree->left = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = hinge;
	hinge->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = hinge;
		else
			tmp->right = hinge;
	}
	return (hinge);
}
