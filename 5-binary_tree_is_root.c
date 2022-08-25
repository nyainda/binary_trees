#include "binary_trees.h"

/**
  * binary_tree_is_root - checks if a given node is a root
  * @node: pointer to node
  *
  * Return: 1 if true, else 0; 0 if node is NULL
  */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	else
		return (1);
}
