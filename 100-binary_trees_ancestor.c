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

/**
 * binary_trees_ancestor - get common ancestor
 * @first: first node
 * @second: second node
 * Return: common anscestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *par1, *par2;
	size_t depth1, depth2;

	if (!first || !second)
		return (NULL);
	par1 = first->parent;
	par2 = second->parent;
	if (par1 == second)
		return (par1);
	if (par2 == first)
		return (par2);
	depth1 = binary_tree_depth(first);
	depth2 = binary_tree_depth(second);
	while (depth1 < depth2)
	{
		depth2 = binary_tree_depth(par2);
		par2 = par2->parent;
	}
	while (depth2 < depth1)
	{
		depth1 = binary_tree_depth(par1);
		par1 = par1->parent;
	}
	while (par1 && par2 && (par1 != par2))
	{
		par1 = par1->parent;
		par2 = par2->parent;
	}
	if (par1 && par2 && (par1 == par2 || first == par2 || second == par1))
		return (par1);
	return (NULL);
}
