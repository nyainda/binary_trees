#include "binary_trees.h"

/**
 * binary_tree_rotate_right - right rotate binary tree
 * @tree: pointer to the root node
 * Description: 23. Rotate right
 * Return: pointer to new root node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
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
	new = tree->left;
	/* set pointer to new root's right child */
	tree->left = new->right;
	/* if a new root's right child is valid, then */
	/* new root will become the tree */
	if (new->right != NULL)
		new->right->parent = tree;
	/* swap parents */
	new->parent = tree->parent;
	/* if there's no parent, current root will point to new root */
	/* else if current root's parent has a right child, point it to new root */
	/* all else, point current root's parent's left child to new root */
	if (tree->parent == NULL)
		root = new;
	else if (tree == tree->parent->right)
		tree->parent->right = new;
	else
		tree->parent->left = new;
	/* move tree to the right of new */
	new->right = tree;
	tree->parent = new;
	/* if current root is not NULL, return it, otherwise return new root*/
	if (root)
		return (root);
	return (new);
}
