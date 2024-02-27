#include "binary_trees.h"

/**
  * binary_tree_postorder - Goes through a binary tree using post-order traversal
  * @tree: Pointer ton the root node of the tree to traverse
  * @func: Pointer to a function to call for each node
  *
  * Return: 0 if tree or func is NULL
  */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		func(tree->n);
		binary_tree_postorder(tree->right, func);
	}
}
