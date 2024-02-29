#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_parent;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	new_parent = tree->left;
	tree->left = new_parent->right;

	if (new_parent->right != NULL)
	{
		new_parent->right->parent = tree;
	}

	new_parent->right = tree;
	new_parent->parent = tree->parent;
	tree->parent = new_parent;

	return (new_parent);
}
