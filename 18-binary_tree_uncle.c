#include "binary_trees.h"

/**
 * binary_tree_uncle - function that finds the uncle of a node
 *
 * @node: pointer to the node to find the uncle
 *
 * Return: If node is NULL, return NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent = NULL;
	binary_tree_t *grand_parent = NULL;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	parent = node->parent;
	grand_parent = parent->parent;

	if (grand_parent->left && grand_parent->left != parent)
		return (grand_parent->left);

	if (grand_parent->right && grand_parent->right != parent)
		return (grand_parent->right);

	else
		return (NULL);
}