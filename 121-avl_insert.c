#include "binary_trees.h"

size_t h(const binary_tree_t *tree);
int balance_factor(const binary_tree_t *tree);
avl_t *avl_tree_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: root node of the tree
 *
 * Return: tree height, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t r_side, l_side;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	l_side = binary_tree_height(tree->left);
	r_side = binary_tree_height(tree->right);

	if (l_side > r_side)
		return (l_side + 1);
	return (r_side + 1);
}

/**
 * h - Measures the h of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the h.
 *
 * Return: If tree is NULL, your function must return 0, else return h.
 */
size_t h(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * balance_factor - Measures the balance_factor factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the
 * balance_factor factor.
 *
 * Return: If tree is NULL, return 0, else return balance_factor factor.
 */
int balance_factor(const binary_tree_t *tree)
{
	return (tree != NULL ? h(tree->left) - h(tree->right) : 0);
}

/**
 * avl_tree_insert_recursive - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avl_tree_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int bfactor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_tree_insert_recursive(&(*tree)->left, *tree,
				new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_tree_insert_recursive(&(*tree)->right, *tree,
				new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bfactor = balance_factor(*tree);
	if (bfactor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfactor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfactor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_tree_insert_recursive(tree, *tree, &new, value);
	return (new);
}

