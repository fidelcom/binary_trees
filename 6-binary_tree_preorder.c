#include "binary_trees.h"

/**
 * binary_tree_preorder - traverses through a binary tree using preorder method
 * @tree: poimnter to the root node of the tree
 * @func: pointer to a function to call for each node
 * Return: void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);

	 binary_tree_preorder(tree->left, func);
	 binary_tree_preorder(tree->right, func);
}
