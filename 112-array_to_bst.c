#include "binary_trees.h"

/**
  * array_to_bst - Builds a Binary Search Tree from an array
  * @array: A pointer to the first element of the array to be converted
  * @size: A number of element in an array
  *
  * Return: A pointer to the root node of the created BST
  *	or NULL if fsilure
  */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t j, k;

	if (array == NULL)
		return (NULL);

	for (j = 0; j < size; j++)
	{
		for (k = 0; k < j; k++)
		{
			if (array[k] == array[j])
				break;
		}
		if (k == j)
		{
			if (bst_insert(&tree, array[j]) == NULL)
				return (NULL);
		}
	}
	return (tree);
}
