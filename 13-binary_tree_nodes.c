#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes.
 * @tree: pointer
 * Return: 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t t = 0, h;

	if (tree)
	{
		if (tree->left || tree->right)
			h = 1;
		else
			h = 0;
		t = t + h;
		t += binary_tree_nodes(tree->left);
		t += binary_tree_nodes(tree->right);
	}
	return (t);
}

