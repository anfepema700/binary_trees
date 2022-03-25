#include "binary_trees.h"

/**
 * binary_tree_sibling - function that finds the sibling of a node
 *
 * @node: pointer to the node to find the sibling
 *
 * Return: node is NULL or the parent is NULL, return NULL
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent = NULL;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	parent = node->parent;

	if (parent->left && parent->left != node)
		return (parent->left);

	if (parent->right && parent->right != node)
		return (parent->right);

	else
		return (NULL);

}