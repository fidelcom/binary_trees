#include "binary_trees.h"

/**
  * binary_tree_depth_check - function that measures the depth
  * of a node in a binary tree
  * @tree: pointer to the node to measure the depth
  *
  * Return: If tree is NULL, your function must return 0
  */
size_t binary_tree_depth_check(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		tree = tree->parent;
		count += 1;
	}
	return (count);
}

/**
  * binary_trees_ancestor - function that finds the lowest
  * common ancestor of two nodes
  * @first: is a pointer to the first node
  * @second: is a pointer to the second node
  *
  * Return: a pointer to the lowest common ancestor node of the two given nodes
  */

binary_tree_t *binary_trees_ancestor(const binary_tree_t
*first, const binary_tree_t *second)
{
	size_t depth_first = 0, depth_second = 0;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	depth_first = binary_tree_depth_check(first);
	depth_second = binary_tree_depth_check(second);

	while (depth_first > depth_second)
	{
		if (first->parent == second)
			return ((binary_tree_t *)second);
		first = first->parent;
		depth_first -= 1;
	}

	while (depth_second > depth_first)
	{
		if (second->parent == first)
			return ((binary_tree_t *)first);
		second = second->parent;
		depth_second -= 1;
	}

	while (first->parent != second->parent)
	{
		first = first->parent;
		second = second->parent;
	}

	return ((binary_tree_t *)first->parent);
}

