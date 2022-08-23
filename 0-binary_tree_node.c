#include "binary_trees.h"
/**
 * binary_tree_node - create node
 * @parent: parent node
 * @value: Node value
 * Return: new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *Node;

	Node = malloc(sizeof(binary_tree_t));
	if (!Node)
		return (NULL);
	Node->left = NULL;
	Node->right = NULL;
	Node->n = value;
	Node->parent = parent;
	return (Node);
}
