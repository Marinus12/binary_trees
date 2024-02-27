#include "binary_trees.h"

/**
  * binary_tree_insert_right - Inserts node as the right-child odf another
  * @parent: Pointer to the node to insert the right-child in
  * @value: Value to store in the new node
  *
  * Return: A pointer to the new node
  */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *current;

	if (parent == NULL)
		return (NULL);

	current = binary_tree_node(parent, value);
	if (current == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		current->right = parent->right;
		parent->right->parent = current;
	}
	parent->right = current;
	return (current);
}
