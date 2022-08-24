#include "binary_trees.h"
/**
 * binary_tree_rotate_right - rotate tree to right
 * @tree: root node
 * Return: new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{

	binary_tree_t *root;

	if (!tree || !tree->left)
		return (NULL);
	root = tree->left;
	root->parent = NULL;
	tree->parent = root;
	if (root->right)
	{
		tree->left = root->right;
		if (tree->left)
			tree->left->parent = tree;
	}
	else
	{
		tree->left = tree->right;
		tree->right = NULL;
	}
	root->right = tree;
	return (root);
}
