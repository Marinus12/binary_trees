#include "binary_trees.h"

/**
  * binary_tree_rotate_left - Performs a left rotation on a binary tree
  * @tree: A pointer to the root node of the tree to rotate
  *
  * Return: A pointer to the root node of the newroot node of the tree
  */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *hinge, *tmp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	hinge = tree->right;
	tmp = hinge->left;
	hinge->left = tree;
	tree->right = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tmp->parent;
	tree->parent = hinge;
	hinge->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = hinge;
		else
			tmp->rigjht = hinge;
	}
	return (hinge);
}
