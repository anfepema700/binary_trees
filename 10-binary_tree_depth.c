#include "binary_trees.h"

/**
 * binary_tree_depth - function that measures the depth
 * of a node in a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL return 0
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t parent_depth;

	if (tree == NULL)
		return (0);

	if (tree->parent == NULL)
		return (0);

	else
	{
		parent_depth = binary_tree_depth(tree->parent);

		return (parent_depth + 1);
	}
}
