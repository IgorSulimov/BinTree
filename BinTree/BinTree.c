#include "BinTree.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

BinTreeNode* Find(BinTreeNode* tree, int data)
{
	if (tree == NULL)
		return NULL;

	if (data = tree->data)	
		return data;
	if (data > tree->data)
		return Find(tree->right, data);
	if (data < tree->data)
		return Find(tree->left, data);
}

void Insert(BinTreeNode** tree_, BinTreeNode* node_)
{
    if (*tree_ == 0)
        *tree_ = node_;
    else
    {
        node_->parent = *tree_;
        if (node_->data >= (*tree_)->data)
            Insert(&(*tree_)->right, node_);
        else if (node_->data < (*tree_)->data)
            Insert(&(*tree_)->left, node_);
    }
}
void Remove(BinTreeNode* tree_, int data_)
{
    if (tree_ == 0)
        return;

    if (data_ > tree_->data)
        Remove(tree_->right, data_);
    else if (data_ < tree_->data)
        Remove(tree_->left, data_);
    else
    {
        BinTreeNode** child = 0;

        if (tree_->parent != 0)
        {
            if (tree_->parent->left == tree_)
                child = &tree_->parent->left;
            else
                child = &tree_->parent->right;
        }

        if (tree_->left == 0 && tree_->right == 0)
        {
            if (child != 0)
                *child = 0;
        }
        else if (!tree_->left != !tree_->right)
        {
            if (tree_->left != 0)
                *child = tree_->left;
            else
                *child = tree_->right;
        }
        else
        {
            if (tree_->right->left == 0)
            {
                tree_->right->left = tree_->left;
                *child = tree_->right;
            }
            else
            {
                BinTreeNode* copy = tree_->left;

                while (copy->right != 0)
                    copy = copy->right; 

                tree_->data = copy->data;
                copy->parent->right = 0;
                tree_ = copy;
            }
        }

        free(tree_);
    }
}
void Prefix_Traverse(BinTreeNode* tree_, void(*fptr)(BinTreeNode* node_))
{
    if (tree_ == 0)
        return;

    fptr(tree_);

    Prefix_Traverse(tree_->left, fptr);
    Prefix_Traverse(tree_->right, fptr);
}
BinTreeNode* CreateNode(int data_)
{
    BinTreeNode* node = malloc(sizeof(BinTreeNode));
    if (node == NULL)
        return NULL;

    node->data = data_;
    node->parent = 0;
    node->left = 0;
    node->right = 0;

    return node;
}

int Min_element(BinTreeNode* tree_)
{
    int min = 0;
    if (tree_ == NULL)
        return NULL;
    if (tree_->left == 0) 
    {
        min = tree_->data;
        return min;
    }
    BinTreeNode* copy = tree_->left;

    while (copy->left != 0)
        copy = copy->left;

    min = copy->data;
    return min;
}

int Max_element(BinTreeNode* tree_)
{
    int max = 0;
    if (tree_ == NULL)
        return NULL;
    if (tree_->right == 0)
    {
        max = tree_->data;
        return max;
    }
    BinTreeNode* copy = tree_->right;

    while (copy->right != 0)
        copy = copy->right;

    max = copy->data;
    return max;
}


int RepeatEl(BinTreeNode* tree_, int data_)
{
    if (tree_ == NULL)
        return 0;
    
    int count;
        if ((tree_->data == data_))
            count = 1;
        else
            count = 0;

    count += RepeatEl(tree_->left, data_);
    count += RepeatEl(tree_->right, data_);
    
    return count;
}

void Print_BinTree(BinTreeNode* tree_) 
{
    if (tree_ == NULL) return;
    Print_BinTree(tree_->left);
    printf("%d\n", tree_->data);
    Print_BinTree(tree_->right);
}

int Sum_BinTree(BinTreeNode* root_)
{
    if (root_ == NULL) return 0;
    return root_->data + Sum_BinTree(root_->left) + Sum_BinTree(root_->right);
}

void Sorted_BinTree(int* array,BinTreeNode* tree_)
{
    int k = 0;
    Sort(array, tree_, k);
}

void Sort(int* ar2, BinTreeNode* tree, int k)
{
    if (tree == NULL)
        return; 
    Sort(ar2, tree->left, k);
    Sort(ar2, tree->right, k);
    ar2[k++] = tree->data;
}

void Print_List(BinTreeNode* tree_)
{
    if (tree_ == NULL)
        return 0;

    int count;
    if ((tree_->left == NULL && tree_->right == NULL))
        count = 1;
    else
        count = 0;

    Print_List(tree_->left);
    if (count == 1)
        printf("%d\n", tree_->data);
    Print_List(tree_->right);

}


int Max_Depth(BinTreeNode* tree_)
{
      if (tree_ == NULL)
            return 0;
        else {
            int lDepth = Max_Depth(tree_->left);
            int rDepth = Max_Depth(tree_->right);

            if (lDepth > rDepth)
                return (lDepth + 1);
            else
                return (rDepth + 1);
        }
}

int Find_Depth(BinTreeNode* tree_, int data_, int depth) 
{
    if (tree_ == NULL) {
        return -1;
    }

    if (tree_->data == data_) {
        return depth;
    }

    int lDepth = Find_Depth(tree_->left, data_, depth + 1);

    if (lDepth != -1) {
        return lDepth;
    }

    int rDepth = Find_Depth(tree_->right, data_, depth + 1);

    if (rDepth != -1) {
        return rDepth;
    }
}

int Num_dep_el(BinTreeNode* tree_, int depth) 
{
    if (tree_ == NULL) return 0;
    if (depth == 0) return 1;

    return Num_dep_el(tree_->left, depth - 1) + Num_dep_el(tree_->right, depth - 1);
}


