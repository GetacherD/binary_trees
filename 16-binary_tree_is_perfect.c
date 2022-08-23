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
 * binary_tree_is_full - check if tree is full
 * @tree: root node
 * Return: 1 if full else 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left == NULL && tree->right)
		return (0);
	if (tree->left && tree->right == NULL)
		return (0);
	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
/**
 * binary_tree_size - get size of bianry tree
 * @tree: tree whose size required
 * Return: size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if ((tree->left == NULL) && (tree->right == NULL))
		return (1);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
/**
 * binary_tree_is_perfect - check if tree is perfect
 * @tree: root node
 * Return: 1 if perfect else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{

	if (binary_tree_is_full(tree))
	{
		if (binary_tree_height(tree->left)
				== binary_tree_height(tree->right))
		{
			if (binary_tree_size(tree->left) == binary_tree_size(tree->right))
				return (1);
		}
	}
	return (0);
}

