#include "binary_trees.h"

int recurse_for_complete(const binary_tree_t *tree, size_t index, size_t size);
size_t binary_tree_size(const binary_tree_t *tree);
int helper_is_heap(const binary_tree_t *tree);

/**
 * binary_tree_is_heap - checks for max binary heap
 * @tree: pointer to the root node
 * Description: 36. Is Binary heap
 * Return: see below
 * 1. upon success, return 1
 * 2. upon fail, return 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	/* check if it's a complete binary tree */
	/* check evey node is greater than or equal to its child */
	if (binary_tree_is_complete(tree) && helper_is_heap(tree))
		return (1);
	return (0);
}

/**
 * helper_is_heap - checks binary heap property
 * @tree: pointer to the root node
 * Description: 36. Is Binary heap
 * Return: see below
 * 1. upon success, return 1
 * 2. upon fail, return 0
 */
int helper_is_heap(const binary_tree_t *tree)
{
	/* if there's no tree */
	if (tree == NULL)
		return (0);

	/* if there' only a root node */
	if ((tree->left == NULL) && (tree->right == NULL))
		return (1);

	/* check second to last level */
	if (tree->right == NULL)
		return (tree->n >= tree->left->n);

	/* recursively check left and right subtrees */
	if ((tree->n >= tree->left->n) && (tree->n >= tree->right->n))
		return (binary_tree_is_heap(tree->left) && binary_tree_is_heap(tree->right));

	return (0);
}

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
