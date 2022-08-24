#include "binary_trees.h"
/**
 * binary_tree_is_leaf - check if node is a leaf
 * @node: node to be checked
 * Return: 1 if node is leaf else 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{

	if (!node)
		return (0);
	if ((node->left == NULL) && (node->right == NULL))
		return (1);
	return (0);
}
/**
 * is_bst - check if binary tree is bst
 * @tree: root node
 * Return: 1 if bst else 0
 */
int is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->left && tree->right == NULL)
	{
		if (tree->left->n <= tree->n)
		{
			return (is_bst(tree->left));
		}
		return (0);
	}
	if (tree->left == NULL && tree->right)
	{
		if (tree->n <= tree->right->n)
		{
			return (is_bst(tree->right));
		}
		return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left->n <= tree->n && tree->right->n >= tree->n)
		return (is_bst(tree->left)
			&& is_bst(tree->right));
	return (0);

}
int MIN(int a, int b, int c)
{
	if (b < a && b < c)
		return (b);
	if (c < b && c < a)
		return (c);
	return (a);
}
int MAX(int a, int b, int c)
{
	if (b > a && b > c)
		return (b);
	if (c > b && c > a)
		return (c);
	return (a);
}

int node_min(binary_tree_t *tree, int min)
{

	if (!tree)
		return (INT_MIN);
	if (binary_tree_is_leaf(tree))
	{
		if (tree->n < min)
		{
			min = tree->n;
			return (tree->n);
		}
		return (min);
	}
	return (MIN(node_min(tree->left, min),
		node_min(tree->right, min), tree->n));
}
int node_max(binary_tree_t *tree, int max)
{

	if (!tree)
		return (INT_MAX);
	if (binary_tree_is_leaf(tree))
	{
		if (tree->n < max)
		{
			max = tree->n;
			return (tree->n);
		}
		return (max);
	}
	return (MAX(node_max(tree->left, tree->n),
		node_max(tree->right, tree->n), tree->n));
}

/**
 * binary_tree_is_bst - check if binary tree is bst
 * @tree: root node
 * Return: 1 if bst else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{

	if (!tree)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);

	if (is_bst(tree))
	{
		if ((node_max(tree->left, INT_MIN) <= tree->n)
				&& (node_min(tree->right, INT_MAX) >= tree->n))
			return (1);
		return (0);
	}
	return (0);

}
