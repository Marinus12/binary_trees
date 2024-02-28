#include "binary_trees.h"

/**
  * bst_insert - Insert a value in Binary Search Tree.
  * @tree: A double pointer to the root node if the BST to insert the value
  * @value: The value to store in he node to be inserted.
  *
  * Return: A pointer to the created node, or NULL on failure.
  */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp, *rec;

	if (tree != NULL)
	{
		tmp = *tree;

		if (tmp == NULL)
		{
			rec = binary_tree_node(tmp, value);
			if (rec == NULL)
				return (NULL);
			return (*tree = rec);
		}

		if (value < tmp->n)
		{
			if (tmp->left != NULL)
				return (bst_insert(&tmp->left, value));

			rec = binary_tree_node(tmp, value);
			if (rec == NULL)
				return (NULL);
			return (tmp->left = rec);
		}
		if (value > tmp->n)
		{
			if (tmp->right != NULL)
				return (bst_insert(&tmp->right, value));
			rec = binary_tree_node(tmp, value);
			if (rec == NULL)
				return (NULL);
			return (tmp->right = rec);
		}
	}
	return (NULL);
}
