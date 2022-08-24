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
 * rightup - move right tree up
 * @first: left node
 * @second: right node
 * @depth1: depth of first node
 * Return: common ancesstor
 */
binary_tree_t *rightup(const binary_tree_t *first,
		const binary_tree_t *second, size_t depth1)
{
	binary_tree_t *par1, *par2;
	size_t depth2;

	par2 = second->parent;
	depth2 = binary_tree_depth(par2);
	while (depth1 != depth2)
	{
		par2 = par2->parent;
		depth2 = binary_tree_depth(par2);
	}
	if (par2 == first)
		return (par2);
	par1 = first->parent;
	par2 = par2->parent;
	while (par1 && par2 && (par1 != par2))
	{
		par1 = par1->parent;
		par2 = par2->parent;
	}
	if (par1 && par2 && (par1 == par2))
		return (par1);
	return (NULL);
}
/**
 * leftup - move left node up
 * @first: left node
 * @second: right node
 * @depth2: depth of second node
 * Return: common ancestor
 */
binary_tree_t *leftup(const binary_tree_t *first,
		const binary_tree_t *second, size_t depth2)
{
	binary_tree_t *par1, *par2;
	size_t depth1;

	par1 = first->parent;
	depth1 = binary_tree_depth(par1);
	while (depth1 != depth2)
	{
		par1 = par1->parent;
		depth1 = binary_tree_depth(par1);
	}
	if (par1 == second)
		return (par1);
	par1 = par1->parent;
	par2 = second->parent;
	while (par1 && par2 && (par1 != par2))
	{
		par1 = par1->parent;
		par2 = par2->parent;
	}
	if (par1 && par2 && (par1 == par2))
		return (par1);
	return (NULL);
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
	depth1 = binary_tree_depth(first);
	depth2 = binary_tree_depth(second);
	if (depth1 < depth2)
		return (rightup(first, second, depth1));
	else if (depth2 < depth1)
		return (leftup(first, second, depth2));
	if (first == second)
		return ((binary_tree_t *)first);
	par1 = first->parent;
	par2 = second->parent;
	while (par1 && par2 && (par1 != par2))
	{
		par1 = par1->parent;
		par2 = par2->parent;
	}
	if (par1 && par2 && (par1 == par2))
		return (par1);
	return (NULL);
}
