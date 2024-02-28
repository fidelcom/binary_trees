#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_tree - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: length of printed tree after process
 */
static int print_tree(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int wide, l, r, is_l, i;

	if (!tree)
		return (0);
	is_l = (tree->parent && tree->parent->left == tree);
	wide = sprintf(b, "(%03d)", tree->n);
	l = print_tree(tree->left, offset, depth + 1, s);
	r = print_tree(tree->right, offset + l + wide, depth + 1, s);
	for (i = 0; i < wide; i++)
		s[depth][offset + l + i] = b[i];
	if (depth && is_l)
	{
		for (i = 0; i < wide + r; i++)
			s[depth - 1][offset + l + wide / 2 + i] = '-';
		s[depth - 1][offset + l + wide / 2] = '.';
	}
	else if (depth && !is_l)
	{
		for (i = 0; i < l + wide; i++)
			s[depth - 1][offset - wide / 2 + i] = '-';
		s[depth - 1][offset + l + wide / 2] = '.';
	}
	return (l + wide + r);
}

/**
 * _ht - Measures the ht of a binary tree
 *
 * @tree: Pointer to the node to measures the ht
 *
 * Return: The height of the tree starting at @node
 */
static size_t _ht(const binary_tree_t *tree)
{
	size_t ht_l;
	size_t ht_r;

	ht_l = tree->left ? 1 + _ht(tree->left) : 0;
	ht_r = tree->right ? 1 + _ht(tree->right) : 0;
	return (ht_l > ht_r ? ht_l : ht_r);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t ht, i, j;

	if (!tree)
		return;
	ht = _ht(tree);
	s = malloc(sizeof(*s) * (ht + 1));
	if (!s)
		return;
	for (i = 0; i < ht + 1; i++)
	{
		s[i] = malloc(sizeof(**s) * 255);
		if (!s[i])
			return;
		memset(s[i], 32, 255);
	}
	print_tree(tree, 0, 0, s);
	for (i = 0; i < ht + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[i][j] != ' ')
				break;
			s[i][j] = '\0';
		}
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}

