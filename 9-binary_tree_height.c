#include "binary_trees.h"
/**
 * binary_tree_height - return height of binary tree
 * @tree: tree whose height required
 * Return: height  of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	left = 1 + binary_tree_height(tree->left);
	right = 1 + binary_tree_height(tree->right);
	if (left >= right)
		return (left);
	return (right);
}
