#include "binary_trees.h"
/**
 * balance - get balance of binary tree
 * @tree: root of binary tree
 * Return: balance of node
 */
int balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left && tree->right == NULL)
		return (1 + balance(tree->right) + balance(tree->left));
	if (tree->left == NULL && tree->right == NULL)
		return (balance(tree->left) + balance(tree->right));
	if (tree->left == NULL && tree->right)
		return (-1 + balance(tree->left) + balance(tree->right));
	return (balance(tree->left) + balance(tree->right));
}
/**
 * binary_tree_balance - get balance including  height
 * @tree: root node
 * Return: balance of node
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	return (balance(tree)
		+ binary_tree_height(tree->left)
		- binary_tree_height(tree->right));
}
