#include "binary_trees.h"
int recurse_for_is_bst(const binary_tree_t *tree, int min, int max);
/**
 * binary_tree_is_bst - check if tree is BST
 * @tree: tree to check
 *
 * Return: 1 is BST; 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree) /* if either pointer is NULL */
		return (0);

	return (recurse_for_is_bst(tree, INT_MIN, INT_MAX));
}
/**
 * recurse_for_is_bst - recursive check for BST
 * @tree: pointer to root node
 * @min: current minimum
 * @max: current maximum
 *
 * Return: 1 if BST; 0 if not
 */
int recurse_for_is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree) /* if either pointer is NULL */
		return (1);

	if ((tree->n < min) || (tree->n > max))
		return (0);

	return (recurse_for_is_bst(tree->left, min, tree->n - 1)
		&& recurse_for_is_bst(tree->right, tree->n + 1, max));
}
