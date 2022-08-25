#include "binary_trees.h"

/**
  * _binary_tree_height - helper func for binary_treee_height
  * @tree: input binary tree.
  *
  * Return: height of tree.
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
  * @tree: input binary tree.
  *
  * Return: height of tree
  */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (_binary_tree_height(tree) - 1);
}

/**
  * binary_tree_balance - measures balance factor of a binary tree.
  * @tree: input binary tree.
  *
  * Return: balance factor of descendants.
  */
int binary_tree_balance(const binary_tree_t *tree)
{
	int c, d;

	if (!tree)
		return (0);
	c = (tree->left)
		? (int)binary_tree_height(tree->left)
		: -1;
	d = (tree->right)
		? (int)binary_tree_height(tree->right)
		: -1;
	return (c -d);
}
