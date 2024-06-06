#include <stdio.h>
#include <stdlib.h>

#include "BinTree.h"

void Print(BinTreeNode* node_)
{
    printf("%d\n", node_->data);
}

int main()
{
    //int max = 0;
    //int array[7] = { 1,10,2,155,4,8,15 };
    BinTreeNode* tree = 0;
    //for (int i = 0; i < 7; i++)
    //{
    //    Insert(&tree, CreateNode(array[i]));
    //}
    int rem = 10;
    int rp = 30;
    int element = 40;
    int depth = 4;
    Insert(&tree, CreateNode(20));
    Insert(&tree, CreateNode(15));
    Insert(&tree, CreateNode(10));
    Insert(&tree, CreateNode(11));
    Insert(&tree, CreateNode(9));
    Insert(&tree, CreateNode(30));
    Insert(&tree, CreateNode(30));
    Insert(&tree, CreateNode(29));
    Insert(&tree, CreateNode(35));
    Insert(&tree, CreateNode(33));
    Insert(&tree, CreateNode(31));
    Insert(&tree, CreateNode(40));
    printf("Prefix_Traverse:\n");
    Prefix_Traverse(tree, Print);
    printf("\nMIN:\n");
    printf("%d\n\n", Min_element(tree));
    printf("MAX:\n");
    printf("%d\n\n", Max_element(tree));
    printf("Remove: %d\n", rem);
    Remove(tree, rem);
    Prefix_Traverse(tree, Print);
    printf("\nSUM:\n");
    printf("%d\n",Sum_BinTree(tree));
    printf("\nNumber of repetitions of the number %d\n", rp);
    printf("%d\n", RepeatEl(tree, rp));
    printf("\nAll List:\n");
    Print_List(tree);
    printf("\nMax_Depth:\n");
    printf("%d\n",Max_Depth(tree));
    printf("\nFind_Depth %d\n", element);
    printf("%d\n", Find_Depth(tree, element, 0));
    printf("\nCount element in depth = %d\n", depth);
    printf("%d\n", Num_dep_el(tree, depth));
    printf("\nSorted Tree:\n");
    Print_BinTree(tree);



    return 0;
}