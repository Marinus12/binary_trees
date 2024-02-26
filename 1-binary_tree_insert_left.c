#include "binary_trees.h"

/**
  * binary_tree_insert_left: Inserts a node as the left-child of another node
  * @parent: Pointer to the node to insert the left-child in
  * @value: The value to store in the new node
  *
  * Return: A pointer to the created, or NULL on failure
  */
binary_tree_t *binary_tree_insert(binary_tree_t *parent, int value)
{
	binary_tree_t *current;

	if (parent == NULL)
		return (NULL);

	current = binary_tree_node(parent, value);
	if (current == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		current->left =parent->left;
		parent->left->parent = current;
	}
	parent->left = current;
	return (current);
}
