#include "binary_trees.h"
/**
 * binary_tree_rotate_left - rotate left the root
 * @tree: root node
 * Return: new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *right;

	if (!tree)
		return (NULL);
	if (!tree->right)
		return (NULL);

	right = tree->right;
	right->parent = NULL;
	tree->parent = right;
	if (!tree->left)
	{
		tree->left = right->left;
		tree->right = NULL;
	}
	else
		tree->right = right->left;
	right->left = tree;
	return (right);
}
