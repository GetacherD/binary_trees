#include "binary_trees.h"
/**
 * binary_tree_insert_left - insert node to left of parent
 * @parent: parent node
 * @value: value of new node
 * Return: inserted node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *Node;

	if (!parent)
		return (NULL);
	Node = binary_tree_node(parent, value);
	if (!Node)
		return (NULL);
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
