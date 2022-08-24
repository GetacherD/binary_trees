#include "binary_trees.h"
/**
 * binary_tree_rotate_right - rotate tree to right
 * @tree: root node
 * Return: new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{

	binary_tree_t *root;

	if (!tree)
		return (NULL);
	if (!tree->left)
		return (tree);
	root = tree->left;
	root->parent = NULL;
	tree->parent = root;
	if (!tree->right)
	{
		tree->right = root->right;
		tree->left = NULL;
	}
	else
		tree->left = root->right;
	root->right = tree;
	return (root);
}