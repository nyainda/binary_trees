#include "binary_trees.h"

/**
  * binary_tree_node - creates a binary tree node
  * @parent: pointer to parent node
  * @value: input value
  *
  * Return: pointer to new node
  */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *binary_tree_node = NULL;

	binary_tree_node = calloc(1, sizeof(binary_tree_t));
	if (!binary_tree_node)
		return (NULL);
	binary_tree_node->parent = parent;
	binary_tree_node->n = value;
	return (binary_tree_node);
}