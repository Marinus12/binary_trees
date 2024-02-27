#include "binary_trees.h"

/**
  * binary_tree_inorder - Goes through a binary tree using in-order traversal
  * @tree: A pointer to the root node of the tree to traversal
  * @func: A pointer to a function to call for each node
  *
  * Return: 0 if tree or func is NULL
  */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
