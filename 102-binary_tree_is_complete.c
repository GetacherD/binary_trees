#include "binary_trees.h"
/**
 * first_complete - check if binary tree is complete
 * @tree: root node
 * Return:1 if complete else 0
 */
int first_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if ((!tree->left) && (!tree->right))
		return (1);
	if (tree->left && tree->right == NULL)
		return (1);
	if (tree->left == NULL && tree->right)
		return (0);
	return (binary_tree_is_complete(tree->left)
			&& binary_tree_is_complete(tree->right));
}
/**
 * binary_tree_is_complete - check if binary tree is complete
 * @tree: root node
 * Return:1 if complete else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (first_complete(tree))
	{
		if (!tree)
			return (1);
		if (tree->left == NULL || tree->right == NULL)
			return (1);
		if (tree && tree->left && tree->right)
		{
			if (tree->left->left == NULL || tree->left->right == NULL)
			{
				if (tree->right->left)
					return (0);
				return (1);
			}
			return (1);
		}
		return (binary_tree_is_complete(tree->left)
			&& binary_tree_is_complete(tree->right));
	}
	return (0);
}
