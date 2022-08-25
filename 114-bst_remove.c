#include "binary_trees.h"

bst_t *helper_loop(bst_t *root);

/**
 * bst_remove - removes a node from a BST
 * @root: pointer to the root node
 * @value: value to remove
 * Description: 28. BST - Remove
 * Return: see below
 * 1. upon success, return pointer to new root node
 * 2. upon fail, return NULL
 */
bst_t *bst_remove(bst_t *root, int value)
{
	/* declare and initialize pointer */
	bst_t *new = NULL;

	/* if there's no root node or no given value */
	if (root == NULL)
		return (root);

	/* first search for value on the left subtree */
	/* then search for value on the right subtree */
	if (root->n > value)
		root->left = bst_remove(root->left, value);
	else if (root->n < value)
		root->right = bst_remove(root->right, value);
	else if (root->n == value)
	{
		/* if there's no children */
		if ((root->left == NULL) && (root->right == NULL))
		{
			free(root);
			return (NULL);
		}
		/* if there's one right child */
		if (root->left == NULL)
		{
			new = root->right;
			if (root->parent)
			{
				if (root->parent->left == root)
					root->parent->left = new;
				else
					root->parent->right = new;
			}
			new->parent = root->parent;
			free(root);
			return (new);
		}
		/* if there's one left child */
		else if (root->right == NULL)
		{
			new = root->left;
			if (root->parent)
			{
				if (root->parent->left == root)
					root->parent->left = new;
				else
					root->parent->right = new;
			}
			new->parent = root->parent;
			free(root);
			return (new);
		}
		/* if there's two children */
		else
		{
			new = helper_loop(root->right);
			root->n = new->n;
			root->right = bst_remove(root->right, new->n);
		}
	}
	return (root);
}

/**
 * helper_loop - searches for in-order successor
 * @root: pointer to root node
 * Description: searches in left subtree only
 * Return: pointer to in-order successor
 */
bst_t *helper_loop(bst_t *root)
{
	bst_t *current = root;

	while ((current) && (current->left))
		current = current->left;
	return (current);
}
