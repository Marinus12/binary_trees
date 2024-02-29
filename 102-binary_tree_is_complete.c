#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
  * create_node - Creates a new levelorder_queue_t node.
  * @node: Tree node for the new node to contain
  *
  * Return: NULL if error, otherwise a pointer to the new node.
  */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *tmp;

	tmp = malloc(sizeof(levelorder_queue_t));
	if (tmp == NULL)
		return (NULL);

	tmp->node = node;
	tmp->next = NULL;

	return (tmp);
}

/**
  * free_queue - Frees a levelorder_queue_t queue.
  * @head: A pointer to the head of the queue
  */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
  * push - Pushes a node to the back of a levelorder_queue_t queue
  * @node: The binary tree node to print and push
  * @head: A double pointer to the head of the same queue
  * @tail: A double pointer to the tail of the same queue
  *
  * Description: Exits with a status code of 1 upon malloc failure
  */
void push(binary_tree_t *node, levelorder_queue_t *head
		, levelorder_queue_t **tail)
{
	levelorder_queue_t *tmp;

	tmp = create_node(node);
	if (tmp == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = tmp;
	*tail = tmp;
}

/**
  * pop - Pops the head of a levelorder_queue_t queue
  * @head: The double pointer to the head of the queue.
  */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
  * binary_tree_is_complete - Checks if a binary tree is complete
  * @tree: A pointer to the root node of the tree to check
  *
  * Return: 0 if tree is NULL
  */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *end;
	unsigned char tmp = 0;

	if (tree == NULL)
		return (0);
	head = end = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (tmp == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &end);
		}
		else
			tmp = 1;
		if (head->node->right != NULL)
		{
			if (tmp == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &end);
		}
		else
			tmp = 1;
		pop(&head);
	}
	return (1);
}
