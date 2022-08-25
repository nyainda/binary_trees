#include "binary_trees.h"

/**
  * binary_tree_depth - measures node depth in a binary tree.
  * @tree: input binary tree
  *
  * Return: depth of tree.
  */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	/* i si counter var */
	size_t i = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		i++;
		tree = tree->parent;
	}
	return (i);
}
