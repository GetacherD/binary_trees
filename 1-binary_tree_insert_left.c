#include "binary_trees.h"
/**
 * binary_tree_insert_left - insert node to left of parent
 * @parent: parent node
 * @value: value of new node
 * Return: inserted node or NULL on failue or if parent NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *Node;

	if (!parent)
		return (NULL);
	Node = malloc(sizeof(binary_tree_t));
	if (!Node)
		return (NULL);
	Node->left = NULL;
	Node->right = NULL;
	Node->parent = parent;
	Node->n = value;
	if (parent->left)
	{
		(parent->left)->parent = Node;
		Node->left = parent->left;
		parent->left = Node;
	}
	else
		parent->left = Node;
	return (Node);
}
