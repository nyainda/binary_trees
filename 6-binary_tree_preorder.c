#include "binary_trees.h"

/**
  * binary_tree_preorder - goes through binary tree using pre-order traversal.
  * and performs function call on each node.
  * @tree: pointer to root of tree.
  * @func: pointer to function call for each node.
  */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
