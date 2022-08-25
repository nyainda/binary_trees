#include "binary_trees.h"

/**
 * binary_tree_node - Insert a new node in the tree.
 *
 * @parent: Parent node.
 * @value: Value of the node.
 *
 * Return: Always 0 (Success)
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;
	return (new_node);
}

/**
 * check_new_root - checks the new root
 * @root: root
 * @new_root: new root
 * Return: node
 */
heap_t *check_new_root(heap_t **root, heap_t *new_root)
{
	heap_t *head, *current;

	current = *root;
	while (1)
	{
		if (binary_tree_balance(current))
			current = current->left;
		else if (!binary_tree_balance(current) && current->right)
			current = current->right;
		else if (!binary_tree_balance(current))
			break;
	}
	new_root = current, head = *root;
	if (new_root == head)
		free(head), new_root = NULL;
	else if (new_root->parent == head)
	{
		if (head->right == new_root)
		{
			new_root->left = head->left, head->left->parent = new_root;
			*root = new_root, free(head);
		}
		else
		{
			*root = new_root, free(head);
			new_root->parent = NULL;
			return (NULL);
		}
	}
	else
	{
		new_root->left = head->left, new_root->left->parent = new_root;
		new_root->right = head->right, new_root->right->parent = new_root;
		if (new_root->parent->right == new_root)
			new_root->parent->right = NULL;
		else
			new_root->parent->left = NULL;
		*root = new_root, free(head);
	}
	return (new_root);
}
/**
 * if_check - if statement
 * @new_root: new root
 * @tmp: position
 * @current: position
 * Return: void
 */
void if_check(heap_t *new_root, heap_t *tmp, heap_t *current)
{
	if (new_root->right == tmp)
	{
		current = tmp->left, tmp->left = new_root->left;
		if (tmp->left)
			tmp->left->parent = tmp;
		new_root->left = current;
		if (new_root->left)
			new_root->left->parent = new_root;
		current = tmp->right, tmp->right = new_root;
		new_root->right = current;
	}
	else
	{
		current = tmp->right, tmp->right = new_root->right;
		if (tmp->right)
			tmp->right->parent = tmp;
		new_root->right = current;
		if (new_root->right)
			new_root->right->parent = new_root;
		current = tmp->left, tmp->left = new_root;
		new_root->left = current;
	}
}

/**
 * loop_heap - loop
 * @root: root
 * @new_root: new root
 *
 * Return: void
 */
void loop_heap(heap_t **root, heap_t *new_root)
{
	heap_t *tmp, *current = NULL;

	while (new_root && (new_root->right || new_root->left))
	{
		if (new_root->right && new_root->left)
		{
			if (new_root->right->n > new_root->left->n)
				tmp = new_root->right;
			else
				tmp = new_root->left;
		}
		else if (new_root->left)
			tmp = new_root->left;
		else
			tmp = new_root->right;
		if (tmp->n > new_root->n)
		{
			if_check(new_root, tmp, current);
		if (current)
			current->parent = new_root;

		tmp->parent = new_root->parent;
		if (new_root->parent && new_root->parent->right == new_root)
			new_root->parent->right = tmp;
		else if (new_root->parent)
			new_root->parent->left = tmp;
		new_root->parent = tmp;
		if (tmp && !tmp->parent)
			*root = tmp;
		}
		else
			break;
	}
}

/**
 * heap_extract - removes head
 * @root: root
 *
 * Return: value in root
 */
int heap_extract(heap_t **root)
{
	heap_t *new_root = NULL;
	int value;

	if (!*root)
		return (0);

	value = (*root)->n;
	new_root = check_new_root(root, new_root);
	if (!new_root)
		return (value);
	new_root->parent = NULL;

	loop_heap(root, new_root);
	return (value);
}
