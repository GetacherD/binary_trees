#include "binary_trees.h"
/**
 * binary_tree_depth - get depth of node in binary tree
 * @tree: whole tree
 * Return: depth of node -> distance from the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	binary_tree_t *parent;

	if (!tree)
		return (0);
	parent =  tree->parent;
	while (parent)
	{
		depth++;
		parent = parent->parent;
	}
	return (depth);
}

