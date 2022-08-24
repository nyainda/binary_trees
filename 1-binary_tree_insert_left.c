#include "binary_trees.h"

/**
  * binary_tree_insert_left - inserts a node as left child of another node
  * @parent: pointer to parent node.
  * @value: input value to node.
  *
  * Return: pointer to new node
  */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *binary_tree_insert_left = NULL;

	if (!parent)
		return (NULL);
	binary_tree_insert_left = calloc(1, sizeof(binary_tree_t));
	if (!binary_tree_insert_left)
		return (NULL);
	binary_tree_insert_left->n = value;
	binary_tree_insert_left->parent = parent;
	if (parent->left)
	{
		binary_tree_insert_left->left = parent->left;
		binary_tree_insert_left->left->parent = binary_tree_insert_left;
	}
	parent->left = binary_tree_insert_left;
	return (binary_tree_insert_left);
}
