#include "binary_trees.h"
/**
 * binary_tree_rotate_left - rotate left the root
 * @tree: root node
 * Return: new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root;

	if (!tree)
		return (NULL);
	if (!tree->right)
		return (NULL);

	root = tree->right;
	root->parent = NULL;
	tree->parent = root;
	if (!root->left)
		tree->right = NULL;
	else
	{
		tree->right = root->left;
		tree->right->parent = root;
	}
	root->left = tree;
	return (root);
}
