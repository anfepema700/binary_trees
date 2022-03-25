#include "binary_trees.h"

/**
 * binary_tree_nodes - function that counts the nodes
 * with at least 1 child in a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL return 0
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_node;
	size_t right_node;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	if ((tree->left == NULL && tree->right != NULL) ||
		(tree->left != NULL && tree->right == NULL))
		return (1);

	left_node = binary_tree_nodes(tree->left);
	right_node = binary_tree_nodes(tree->right);

	return (left_node + right_node + 1);
}