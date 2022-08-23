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
 * is_leaf - check if node is a leaf
 * @node: node to be checked
 * Return: 1 if node is leaf else 0
 */
int is_leaf(const binary_tree_t *node)
{

	if (!node)
		return (0);
	if ((node->left == NULL) && (node->right == NULL))
		return (1);
	return (0);
}

/**
 * is_perfect - check if tree is perfect
 * @tree: root node
 * Return: 1 if perfect else 0
 */
int is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->left == NULL && tree->right)
		return (0);
	if (tree->right == NULL && tree->left)
		return (0);
	return (binary_tree_is_perfect(tree->left)
			&& binary_tree_is_perfect(tree->right));

}
/**
 * binary_tree_is_perfect - check if tree is perfect
 * @tree: root node
 * Return: 1 if perfect else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (is_perfect(tree))
	{
		if (binary_tree_height(tree->left)
				!= binary_tree_height(tree->right))
			return (0);
	}
	return (0);

}

