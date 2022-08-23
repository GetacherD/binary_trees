#include "binary_trees.h"
/**
 * binary_tree_leaves - count number of leafs of node
 * @tree: node whose tree required
 * Return: number of leafs
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left  == NULL && tree->right == NULL)
		return (1);
	if (tree->left == NULL || tree->right == NULL)
		return (1);
	return (2);
}
