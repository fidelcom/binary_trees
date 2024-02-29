#include "binary_trees.h"

/**
  * get_binary_tree_height - function that measures the height of a binary tree
  * @tree: a pointer to the root node of the tree to measure the height.
  *
  * Return: If tree is NULL, function must return 0
  */
size_t get_binary_tree_height(const binary_tree_t *tree)
{
	size_t right_side, left_side;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_side = get_binary_tree_height(tree->left);
	right_side = get_binary_tree_height(tree->right);

	if (left_side > right_side)
		return (left_side + 1);
	return (right_side + 1);
}

/**
  * _print_tree_level - Prints a level of a binary tree.
  * @tree: A pointer to the root node of the tree to traverse.
  * @func: A pointer to a function to call for each node.
  * @level: The level of the binary tree to print.
  *
  * Return: Nothing!
  */
void _print_tree_level(const binary_tree_t *tree, void (*func)(int),
		size_t level)
{
	if (tree == NULL)
		return;

	if (level == 0)
		func(tree->n);

	level -= 1;
	_print_tree_level(tree->left, func, level);
	_print_tree_level(tree->right, func, level);
}

/**
  * binary_tree_levelorder - Goes through a binary tree using
  * level-order traversal.
  * @tree: A pointer to the root node of the tree to traverse.
  * @func: A pointer to a function to call for each node.
  *
  * Return: Nothing!
  */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level = 0, tree_size = 0;

	if (tree == NULL || func == NULL)
		return;

	tree_size = get_binary_tree_height(tree);

	for (; level <= tree_size; ++level)
		_print_tree_level(tree, func, level);
}

