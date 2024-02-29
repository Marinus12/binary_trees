#include "binary_trees.h"

/**
 * binary_trees_ancestor - search the common ancestor.
 * @first: Pointer.
 * @second: Pointer.
 * Return: NULL on no ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *t, *u;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	t = first->parent;
	u = second->parent;

	if (first == u || !t || (!t->parent && u))
		return (binary_trees_ancestor(first, u));
  
	else if (t == second || !u || (!u->parent && t))
		return (binary_trees_ancestor(t, second));

	return (binary_trees_ancestor(t, u));
}
