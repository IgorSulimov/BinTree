#pragma once
#include <stdio.h>
#include <stdbool.h>
typedef struct BinTreeNode
{
	struct BinTreeNode* parent;
	struct BinTreeNode* left;
	struct BinTreeNode* right;
	int data;


}BinTreeNode;

void Print_BinTree(BinTreeNode* tree_); // ����� �� ������ �� �������� � ��������

void Prefix_Traverse(BinTreeNode* tree_, void(*fptr)(BinTreeNode* node_));// ���������� ����� �� ������

BinTreeNode* CreateNode(int data_); // �������� �������� ��� ������

BinTreeNode* Find(BinTreeNode* tree, int data); // ���������� �������� � ������  �1

void Insert(BinTreeNode** tree_, BinTreeNode* node_); // ���������� �������� � ������   �1

void Remove(BinTreeNode* tree_, int data_);// �������� �������� ������   �1

int Sum_BinTree(BinTreeNode* tree_); // ����� ��������� ������ � 2

int Max_element(BinTreeNode* tree_);// ������������ ������� � ������  �3

int Min_element(BinTreeNode* tree_);// ����������� ������� � ������   �4

int RepeatEl(BinTreeNode* tree_, int data_);  // ���������� ������������� ��������� � ������ � 5

void Print_List(BinTreeNode* tree_); // ����� ���� ������� ������ �6

int Max_Depth(BinTreeNode* tree_); // ������������ ������� ������ � 10

int Find_Depth(BinTreeNode* tree_, int data_, int depth); // ���������� ������� ��������� �������� �8

void Sort(int* ar2, BinTreeNode* tree, int k);

void Sorted_BinTree(int* array, BinTreeNode* tree_);

int Num_dep_el(BinTreeNode* tree_, int depth); // ���������� ����� ���� ������ � �������� ������� � 9



