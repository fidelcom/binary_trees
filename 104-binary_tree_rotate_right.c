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
		return (tree);

	new_parent = tree->left;
	tree->left = new_parent->right;
	new_parent->right = tree;

	if (tree->parent)
	{
		if (tree->parent->left == tree)
		{
			tree->parent->left = new_parent;
		}
		else
		{
			tree->parent->right = new_parent;
		}
	}

	new_parent->parent = tree->parent;
	tree->parent = new_parent;

	return (new_parent);
}
