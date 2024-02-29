#include "binary_trees.h"

size_t binary_tree_size_t(const binary_tree_t *tree);
int binary_tree_is_complete_check_helper(const binary_tree_t *tree,
		size_t index, size_t size);
/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_complete_check_helper(tree, 0,
				binary_tree_size_t(tree)));
}

/**
 * binary_tree_is_complete_check_helper - Recursive helper function
 * to check completeness.
 * @tree: Pointer to the root node of the tree.
 * @index: Index of the current node.
 * @size: Size of the tree.
 *
 * Return: 1 if the subtree is complete, 0 otherwise.
 */
int binary_tree_is_complete_check_helper(const binary_tree_t *tree,
		size_t index, size_t size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (binary_tree_is_complete_check_helper(tree->left, 2 * index + 1,
				size) && binary_tree_is_complete_check_helper
			(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size_t - Computes the size (number of nodes) of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Size of the tree.
 */
size_t binary_tree_size_t(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size_t(tree->left) +
			binary_tree_size_t(tree->right));
}
