#include "binary_trees.h"
/**
 * binary_tree_preorder - traverse tree in pre_order
 * @tree: tree to be travesed
 * @func: function to be called on each node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (func == NULL)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
