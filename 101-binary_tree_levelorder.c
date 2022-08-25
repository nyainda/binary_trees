#include "binary_trees.h"
size_t recurse_for_height(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
void recurse_for_levelorder(const binary_tree_t *tree,
	void (*func)(int), size_t level);
/**
 * binary_tree_levelorder - traverse tree by level
 * @tree: tree to traverse
 * @func: function pointer
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t c, d = 0;

	if (!tree || !func)
		return;

	/* retrieve height */
	c = binary_tree_height(tree);

	while (d <= c)
	{
		recurse_for_levelorder(tree, func, d);
		d++;
	}
}
void recurse_for_levelorder(const binary_tree_t *tree,
	void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;

	if (level == 0)
		func(tree->n);

	recurse_for_levelorder(tree->left, func, level - 1);
	recurse_for_levelorder(tree->right, func, level - 1);
}
/**
 * binary_tree_height - measure height of tree
 * @tree: tree to measure
 *
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	return (recurse_for_height(tree) - 1);
}
/**
 * recurse_for_height - measure height
 * @tree: tree to measure
 *
 * Return: height
 */
size_t recurse_for_height(const binary_tree_t *tree)
{
	size_t a, b;

	if (!tree)
		return (0);

	b = recurse_for_height(tree->left);
	a = recurse_for_height(tree->right);

	if (b > a)
		return (b + 1);
	else
		return (a + 1);
}
