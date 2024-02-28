#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leafs in a binary tree
 * @tree: root node of the tree
 *
 * Return: Number of leaves in the tree, 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leafs = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	leafs = binary_tree_leaves(tree->left)
		+ binary_tree_leaves(tree->right);

	return (leafs);
}

