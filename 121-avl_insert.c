#include "binary_trees.h"
bst_t *recurse_for_bst_insert(bst_t *tree, int value);
bst_t *bst_insert(bst_t **tree, int value);
void recurse_for_balance(binary_tree_t *tree);
/**
 * avl_insert - insert node into AVL
 * @tree: pointer to root of tree
 * @value: value for inserted node
 *
 * Return: pointer to created node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	bst_t *new_node = NULL, *parent = NULL;

	/* if double pointer is empty */
	if (tree == NULL)
		return (NULL);

	/* if tree doesn't exist, create one */
	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}

	/* find parent node for new node */
	parent = recurse_for_bst_insert(*tree, value);

	if (parent) /* if parent was found, create new node*/
		new_node = binary_tree_node(parent, value);
	else
		return (NULL);

	/* point parent to new node */
	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	/* re-balance tree */
	recurse_for_balance(new_node);

	return (new_node);
}
/**
 * recurse_for_balance - recurse upstream from new node
 * @tree: pointer to root of tree
 */
void recurse_for_balance(binary_tree_t *tree)
{
	int balFactor;

	if (!tree)
		return;

	printf("tree (in balance) = %d\n", tree->n);

	/* take balance factor of every tree/subtree */
	balFactor = binary_tree_balance(tree);

	if (balFactor < -1)
	{
		binary_tree_print(tree);
		tree = binary_tree_rotate_right(tree);
		printf("Rotated right\n");
	}
	else if (balFactor > 1)
	{
		binary_tree_print(tree);
		tree = binary_tree_rotate_left(tree);
		printf("Rotated left\n");
	}
	/* recursively move up tree */
	recurse_for_balance(tree->parent);
}
/**
 * recurse_for_bst_insert - recursively search tree
 * @tree: pointer to root of tree/subtree
 * @value: value being added
 *
 * Return: pointer to parent of new node; NULL on failure
 */
bst_t *recurse_for_bst_insert(bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	/* if value is less than that in node */
	if (value < tree->n)
	{
		if (tree->left != NULL)
			return (recurse_for_bst_insert(tree->left, value));
		else
			return (tree);
	}

	/* if value is greater than that in node */
	else if (value > tree->n)
	{
		if (tree->right != NULL)
		{
			return (recurse_for_bst_insert(tree->right, value));
		}
		else
			return (tree);
	}

	/* will reach if value is equal to value in current node */
	return (NULL);
}
