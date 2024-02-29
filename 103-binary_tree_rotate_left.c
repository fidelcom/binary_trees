#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the three to rotate
 * Return: a pointer to the new root node of the tree after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_parent;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	new_parent = tree->right;
	tree->right = new_parent->left;
	new_parent->left = tree;

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
