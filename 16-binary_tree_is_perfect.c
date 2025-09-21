#include "binary_trees.h"

/**
 * binary_tree_is_perfect_helper - helper function to check if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * @depth: depth of the tree
 * @level: current level of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */

static int binary_tree_is_perfect_helper(const binary_tree_t *tree, int depth, int level)

{
    if (tree == NULL)
        return (1);

    if (tree->left == NULL && tree->right == NULL)
        return (depth == level + 1);

    if (tree->left == NULL || tree->right == NULL)
        return (0);

    return (binary_tree_is_perfect_helper(tree->left, depth, level + 1) &&
            binary_tree_is_perfect_helper(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 *         If tree is NULL, return 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)

{
    int depth;

    if (tree == NULL)
        return (0);

    depth = (int)binary_tree_height(tree) + 1;
    return (binary_tree_is_perfect_helper(tree, depth, 0));
}
