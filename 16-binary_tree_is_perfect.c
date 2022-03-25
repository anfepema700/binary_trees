#include "binary_trees.h"

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: If tree is NULL return 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int h = 0;
	int number_nodes = 0;
	int nodes_comparison = 0;

	if (tree == NULL)
		return (0);

	h = binary_tree_height(tree);
	number_nodes = binary_tree_nodes(tree);
	nodes_comparison = _pow_recursion(2, h + 1) - 1 == number_nodes;

	return (nodes_comparison);
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

	if (tree->left == NULL && tree->right == NULL)
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

/**
 *_pow_recursion - returns the value of x raised to the power of y
 *@x: base
 *@y: power
 *Return: Always 0.
 */
int _pow_recursion(int x, int y)
{
	if (y == 0)   /* Base case */
		return (1);
	if (y < 0)    /* Base case */
		return (-1);
	if (y == 1)   /* Base case */
		return (x);
	if (y > 1)
		return (_pow_recursion(x, y - 1) * x);
	return (0);
}

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
		return (1);

	if ((tree->left == NULL && tree->right != NULL) ||
		(tree->left != NULL && tree->right == NULL))
		return (1);

	left_node = binary_tree_nodes(tree->left);
	right_node = binary_tree_nodes(tree->right);

	return (left_node + right_node + 1);
}