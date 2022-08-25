#include "binary_trees.h"

/**
 * binary_tree_rotate_left - left rotate binary tree
 * @tree: pointer to the root node
 * Description: 22. Rotate left
 * Return: pointer to new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	/* declare and initialize pointers */
	binary_tree_t *new = NULL, *root = NULL;

	/* if root node is NULL */
	if (tree == NULL)
		return (tree);

	/* if root node has no children */
	if ((tree->left == NULL) && (tree->right == NULL))
		return (tree);

	/* set pointer to new root */
	new = tree->right;
	/* set pointer to new root's left child */
	tree->right = new->left;
	/* if a new root's left child is valid, then */
	/* new root will become the tree */
	if (new->left != NULL)
		new->left->parent = tree;
	/* swap parents */
	new->parent = tree->parent;
	/* if there's no parent, current root will point to new root */
	/* else if current root's parent has a left child, point it to new root */
	/* all else, point current root's parent's right child to new root */
	if (tree->parent == NULL)
		root = new;
	else if (tree == tree->parent->left)
		tree->parent->left = new;
	else
		tree->parent->right = new;
	/* move tree to the left of new */
	new->left = tree;
	tree->parent = new;
	/* if current root is not NULL, return it, otherwise return new root*/
	if (root)
		return (root);
	return (new);
}
