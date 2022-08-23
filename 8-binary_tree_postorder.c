#include "binary_trees.h"
/**
 * binary_tree_postorder - traverse tree in post order left  right root
 * @tree: tree to be traversed
 * @func: function to be called on each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return;
	if (!func)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
