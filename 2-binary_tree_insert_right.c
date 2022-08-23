#include "binary_trees.h"
/**
 * binary_tree_insert_right - insert node to right
 * @parent: parent Node
 * @value: Node value
 * Return: pointer to new Node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *Node;

	if (!parent)
		return (NULL);
	Node = malloc(sizeof(binary_tree_t));
	if (!Node)
		return (NULL);
	Node->left = NULL;
	Node->right = NULL;
	Node->n = value;
	Node->parent = parent;
	if (parent->right)
	{
		parent->right->parent = Node;
		Node->right = parent->right;
		parent->right = Node;
	}
	else
		parent->right = Node;
	return (Node);
}
