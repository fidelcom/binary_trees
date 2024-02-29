#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree (BST)
 * @tree: root node of the BST to search
 * @value: value to search in the tree
 *
 * Return: node containing the value, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	else if (value > tree->n)
		return (bst_search(tree->right, value));
	else
		return ((bst_t *)tree);
}

