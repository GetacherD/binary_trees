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
		return (0);
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
