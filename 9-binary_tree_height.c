#include "binary_trees.h"

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

