#include "binary_trees.h"

/**
 * calculate_depth - calculates the depth of the tree
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if tree is NULL, and 1 plus the result of calling the function
 */
int calculate_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		return (1 + calculate_depth(tree->left));
	}
}

/**
 * binary_tree_is_perfect - checks if a tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: i if tree is perfect and 0 if otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (calculate_depth(tree->left) == calculate_depth(tree->right))
	{
		if (binary_tree_is_perfect(tree->left) == 1 &&
				binary_tree_is_perfect(tree->right) == 1)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
	else
	{
		return (0);
	}
}
