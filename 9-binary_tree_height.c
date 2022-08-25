#include "binary_trees.h"

/**
  * _binary_tree_height - helper function for binary_tree_height
  * @tree: input tree
  *
  * Return: height of tree
  */
size_t _binary_tree_height(const binary_tree_t *tree)
{
	size_t c, d;

	if (!tree)
		return (0);

	c = _binary_tree_height(tree->left);
	d = _binary_tree_height(tree->right);
	return (MAX(c, d) + 1);
}

/**
  * binary_tree_height - measures height of a binary tree
  * @tree: input tree
  *
  * Return: height of tree.
  */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (_binary_tree_height(tree) - 1);
}
