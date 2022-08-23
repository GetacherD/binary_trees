#include "binary_trees.h"
/**
 * binary_tree_leaves - count number of leafs of node
 * @tree: node whose tree required
 * Return: number of leafs -> do not count root
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		leaves++;
	leaves += binary_tree_leaves(tree->left);
	leaves += binary_tree_leaves(tree->right);
	return (leaves);
}
