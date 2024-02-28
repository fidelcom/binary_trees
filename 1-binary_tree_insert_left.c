#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: node to insert the left-child in
 * @value: new node value
 *
 * Return: new node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *n_node;

	if (!parent)
		return (NULL);

	n_node = malloc(sizeof(binary_tree_t));
	if (!n_node)
		return (NULL);

	n_node->n = value;
	n_node->parent = parent;
	n_node->left = NULL;
	n_node->right = NULL;

	if (parent->left)
	{
		n_node->left = parent->left;
		parent->left->parent = n_node;
	}

	parent->left = n_node;

	return (n_node);
}

