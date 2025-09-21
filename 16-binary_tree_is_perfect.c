#include "binary_trees.h"

/**
 * get_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */

static size_t get_height(const binary_tree_t *tree)

{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = get_height(tree->left);
	right_height = get_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * get_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */

static size_t get_size(const binary_tree_t *tree)

{
	if (tree == NULL)
		return (0);

	return (1 + get_size(tree->left) + get_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)

{
	size_t height, size, expected_size;
	size_t i;

	if (tree == NULL)
		return (0);

	height = get_height(tree);
	size = get_size(tree);

	expected_size = 1;
	for (i = 0; i <= height; i++)
		expected_size *= 2;
	expected_size -= 1;

	return (size == expected_size);
}
