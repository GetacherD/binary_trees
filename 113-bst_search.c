#include "binary_trees.h"
/**
 * bst_search - search value in bst
 * @tree: root node
 * @value: value to be searched
 * Return: founded node
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);
	if (tree->n > value)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
