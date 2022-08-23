#include "binary_trees.h"
/**
 * binary_tree_inorder - traverse tree in order left node right
 * @tree: tree to be traversed
 * @func: function to be called on each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return;
	if (!func)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
