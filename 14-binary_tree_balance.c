#include "binary_trees.h"
/**
 * binary_tree_balance - get balance of binary tree
 * @tree: root of binary tree
 * Return: balance of node
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left && tree->right == NULL)
		return (1);
	if (tree->left == NULL && tree->right)
		return (-1);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	return (2);
}
