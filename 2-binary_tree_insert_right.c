#include "binary_trees.h"

/**
  * binary_tree_insert_right - inserts a node as right child of another node
  * @parent: pointer to parent node.
  * @value: input value to node.
  *
  * Return: pointer to new node
  */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *binary_tree_insert_right = NULL;

	if (!parent)
		return (NULL);
	binary_tree_insert_right = calloc(1, sizeof(binary_tree_t));
	if (!binary_tree_insert_right)
		return (NULL);
	binary_tree_insert_right->n = value;
	binary_tree_insert_right->parent = parent;
	if (parent->right)
	{
		binary_tree_insert_right->right = parent->right;
		binary_tree_insert_right->right->parent = binary_tree_insert_right;
	}
	parent->right = binary_tree_insert_right;
	return (binary_tree_insert_right);
}
