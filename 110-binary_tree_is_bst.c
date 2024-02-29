#include "binary_trees.h"

/**
 * is_valid_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * @min_val: minimum node value
 * @max_val: maximum node value
 * Return: 1 if tree is a valid BST and 0 otherwise
 */
int is_valid_bst(const binary_tree_t *tree, int min_val, int max_val)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min_val || tree->n >= max_val)
		return (0);

	return (is_valid_bst(tree->left, min_val, tree->n - 1) &&
			is_valid_bst(tree->right, tree->n + 1, max_val));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid BST
 * @tree:  a pointer to the root node of the tree to check
 * Return: 1if tree is a valid BST or 0 if other wise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_valid_bst(tree, INT_MIN, INT_MAX));
}
