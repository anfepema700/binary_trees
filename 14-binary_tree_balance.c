#include "binary_trees.h"

/**
 * binary_tree_balance - function that measures the balance
 * factor of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: If tree is NULL return 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_tree_height - function that measures the height of a binary tree
 * using post-order traversal
 *
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_height = binary_tree_height(tree->left) + 1;
	else
		left_height = 1;

	if (tree->right)
		right_height = binary_tree_height(tree->right) + 1;
	else
		right_height = 1;

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}