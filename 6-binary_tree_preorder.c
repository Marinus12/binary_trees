#include "binary_trees.h"

/**
  * binary_tree_preorder - Goes through a binary tree using a pre-order
  * @tree: Pointer to the root node of the tree to traverse
  * @func: Pointer to a finction to call for each node
  *
  * Return: 0 if tree or func is null
  */
void binary_tree_preorder(const binary_tree_t *tree, void(*func)(int))
{
	if (tree && func)
	{
		func(tree->n);

		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
