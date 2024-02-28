#include "binary_trees.h"

/**
 * h - measures the h of a tree
 *
 * @tree: tree root
 * Return: h
 */
int h(const binary_tree_t *tree)
{
	int l = 0;
	int r = 0;

	if (tree == NULL)
		return (-1);

	l = h(tree->left);
	r = h(tree->right);

	if (l > r)
		return (l + 1);

	return (r + 1);
}

/**
 * binary_tree_check - checks if a binary tree is perfect
 *
 * @tree: tree root
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_check(const binary_tree_t *tree)
{
	if (tree && h(tree->left) == h(tree->right))
	{
		if (h(tree->left) == -1)
			return (1);

		if ((tree->left && !((tree->left)->left) && !((tree->left)->right))
		    && (tree->right && !((tree->right)->left) && !((tree->right)->right)))
			return (1);

		if (tree && tree->left && tree->right)
			return (binary_tree_check(tree->left) &&
				binary_tree_check(tree->right));
	}

	return (0);
}

/**
 * swap_node - swap_nodes nodes when child is greater than parent
 *
 * @arg_node: parent node
 * @arg_child: child node
 * Return: no return
 */
void swap_node(heap_t **arg_node, heap_t **arg_child)
{
	heap_t *node, *child, *node_child, *node_left, *node_right, *parent;
	int left_right;

	node = *arg_node, child = *arg_child;
	if (child->n > node->n)
	{
		if (child->left)
			child->left->parent = node;
		if (child->right)
			child->right->parent = node;
		if (node->left == child)
			node_child = node->right, left_right = 0;
		else
			node_child = node->left, left_right = 1;
		node_left = child->left, node_right = child->right;
		if (left_right == 0)
		{
			child->right = node_child;
			if (node_child)
				node_child->parent = child;
			child->left = node;
		}
		else
		{
			child->left = node_child;
			if (node_child)
				node_child->parent = child;
			child->right = node;
		}
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = child;
			else
				node->parent->right = child;
		}
		parent = node->parent, child->parent = parent;
		node->parent = child, node->left = node_left;
		node->right = node_right, *arg_node = child;
	}
}

/**
 * heap_insert - function that inserts a value in Max Binary Heap
 * @value: value to be inserted
 * @root: tree root
 * Return: pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *n_node;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	if (binary_tree_check(*root) || !binary_tree_check((*root)->left))
	{
		if ((*root)->left)
		{
			n_node = heap_insert(&((*root)->left), value);
			swap_node(root, &((*root)->left));
			return (n_node);
		}
		else
		{
			n_node = (*root)->left = binary_tree_node(*root, value);
			swap_node(root, &((*root)->left));
			return (n_node);
		}
	}

	if ((*root)->right)
	{
		n_node = heap_insert(&((*root)->right), value);
		swap_node(root, (&(*root)->right));
		return (n_node);
	}
	else
	{
		n_node = (*root)->right = binary_tree_node(*root, value);
		swap_node(root, &((*root)->right));
		return (n_node);
	}

	return (NULL);
}

