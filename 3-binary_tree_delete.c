#include "binary_trees.h"
/**
 * binary_tree_delete - delete (free) binary tree
 * @tree: binary tree to be freed
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *NodeLeft, *NodeRight;

	if (!tree)
		return;

	NodeLeft = tree->left;
	NodeRight = tree->right;
	free(tree);
	binary_tree_delete(NodeLeft);
	binary_tree_delete(NodeRight);
}
