#include "binary_trees.h"
/**
 * binary_tree_nodes - get number of nodes having atleat 1 child
 * @tree: parent node
 * Return: number of nodes having at least 1 child
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
