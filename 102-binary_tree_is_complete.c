#include "binary_trees.h"
/**
 * binary_tree_is_complete - check if binary tree is complete
 * @tree: root node
 * Return:1 if complete else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if ((!tree->left) && (!tree->right))
		return (1);
	if (tree->left && tree->right == NULL)
		return (1);
	if (tree->left == NULL && tree->right)
		return (0);
	return (binary_tree_is_complete(tree->left) && binary_tree_is_complete(tree->right));
}
