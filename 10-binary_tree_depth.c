#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the d of a node in a binary tree
 * @tree: node
 *
 * Return: depth of the node, 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t d = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		tree = tree->parent;
		d++;
	}

	return (d);
}

