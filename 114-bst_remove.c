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
/**
 * successor- get next succeesor inorder for node
 * @node: node whose inorder successor required
 * Return: next successor
 */
bst_t *successor(bst_t *node)
{
	bst_t *right;

	if (!node)
		return (NULL);
	right = node->right;
	while (right && right->left)
		right = right->left;
	if (right)
	{
		right->parent->left = NULL;
		return (right);
	}
	return (node->left);
}
/**
 * bst_remove - remove node
 * @root: root node
 * @value: value to be removed
 * Return: new node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *Node, *Repl;

	Node = bst_search(root, value);
	Repl = successor(Node);
	if (Node == NULL || !Repl)
		return (NULL);
	Repl->parent = Node->parent;
	Repl->left = NULL;
	Repl->right = NULL;
	if (Node->parent)
	{
		if (Repl != Node->left)
			Repl->left = Node->left;
		if (Repl != Node->right)
			Repl->right = Node->right;
		if (Node->left && Node->left != Repl)
			Node->left->parent = Repl;
		if (Node->right && Node->right != Repl)
			Node->right->parent = Repl;
		if (Node->parent->left == Node)
			Node->parent->left = Repl;
		else
			Node->parent->right = Repl;
		free(Node);
		return (root);
	}
	if (Repl != Node->left)
		Repl->left = Node->left;
	if (Repl != Node->right)
		Repl->right = Node->right;
	if (Node->left && Node->left != Repl)
		Node->left->parent = Repl;
	if (Node->right && Node->right != Repl)
		Node->right->parent = Repl;
	free(Node);
	return (Repl);
}
