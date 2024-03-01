#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Pointer to the parent node
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *n_node;

	n_node = malloc(sizeof(binary_tree_t));
	if (n_node == NULL)
		return (NULL);

	n_node->parent = parent;
	n_node->n = value;
	n_node->left = NULL;
	n_node->right = NULL;

	return (n_node);
}

/**
 * maxi - Finds the maximum node in a tree.
 * @tree: root of the tree.
 * Return: The node with the maximum v.
 */
heap_t *maxi(heap_t *tree)
{
	heap_t *c_max, *l_max, *r_max;

	if (!tree->left)
		return (tree);
	l_max = maxi(tree->left);
	if (l_max->n > tree->n)
		c_max = l_max;
	else
		c_max = tree;
	if (tree->right)
	{
		r_max = maxi(tree->right);
		if (r_max->n > c_max->n)
			c_max = r_max;
		else
			c_max = tree;
	}
	return (c_max);
}

/**
 * recurse_max_extract - Recursively extracts the max from the tree.
 * @tree: The pointer to the root of the tree.
 */
void recurse_max_extract(heap_t *tree)
{
	heap_t *s_max, *r_max = NULL;

	if (!tree->left)
		return;
	s_max = maxi((tree)->left);
	if (tree->right)
		r_max = maxi(tree->right);
	if (r_max && r_max->n > s_max->n)
		s_max = r_max;
	tree->n = s_max->n;
	if (!s_max->left)
	{
		if (s_max->parent && s_max->parent->left == s_max)
			s_max->parent->left = NULL;
		if (s_max->parent && s_max->parent->right == s_max)
			s_max->parent->right = NULL;
		free(s_max);
	}
	else
		recurse_max_extract(s_max);
}

/**
 * heap_extract - Extracts the root from a Binary Heap.
 * @root: root of the tree.
 * Return: The value of the extracted node.
 */
int heap_extract(heap_t **root)
{
	int v;

	if (!*root)
		return (0);
	v = (*root)->n;
	if (!(*root)->left)
	{
		v = (*root)->n;
		free(*root);
		*root = NULL;
		return (v);
	}
	recurse_max_extract(*root);
	return (v);
}

