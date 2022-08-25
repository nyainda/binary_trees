#include "binary_trees.h"
int recurse_for_complete(const binary_tree_t *tree, size_t index, size_t size);
size_t binary_tree_size(const binary_tree_t *tree);
/**
 * binary_tree_is_complete - check if tree is complete
 * @tree: pointer to root of tree
 *
 * Return: 1 if complete; 0 if incomplete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (recurse_for_complete(tree, 0, binary_tree_size(tree)));
}
/**
 * recurse_for_complete - use array indexing to track node position
 * @tree: pointer to root of tree
 * @index: index of node in conceptual array
 * @size: number of nodes in tree
 *
 * Return: 1 if complete; 0 if incomplete
 */
int recurse_for_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	int left, right;

	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	left = recurse_for_complete(tree->left, (2 * index) + 1, size);
	right = recurse_for_complete(tree->right, (2 * index) + 2, size);

	if (left == 1 && right == 1)
		return (1);
	else
		return (0);
}
/**
 * binary_tree_size - measure size of binary tree
 * @tree: tree to measure
 *
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
	return (0);
}
