#include "binary_trees.h"
/**
 * binary_tree_sibling - Get sibling of node
 * @node: node whose sibling required
 * Return: pointer to sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (!node)
		return (NULL);
	parent = node->parent;
	if (!parent)
		return (NULL);
	if (parent->left == node)
		return (parent->right);
	return (parent->left);
}
/**
 * binary_tree_uncle - get uncle of binary tree
 * @node: node whose uncle required
 * Return: pointer to uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{

	if (!node || !(node->parent))
		return (NULL);
	return (binary_tree_sibling(node->parent));
}

