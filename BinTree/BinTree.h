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

void Print_BinTree(BinTreeNode* tree_); // Обход по дереву от меньшего к большему

void Prefix_Traverse(BinTreeNode* tree_, void(*fptr)(BinTreeNode* node_));// Префиксный обход по дереву

BinTreeNode* CreateNode(int data_); //Создание элемента для дерева

BinTreeNode* Find(BinTreeNode* tree, int data); //Нахождение елемента в дереве ¹1

void Insert(BinTreeNode** tree_, BinTreeNode* node_); //Добавление элемента в дерево   ¹1

void Remove(BinTreeNode* tree_, int data_);//Удаление элемента дерева   ¹1

int Sum_BinTree(BinTreeNode* tree_); // Сумма элементов дерева  ¹ 2

int Max_element(BinTreeNode* tree_);//Максимальный элемент в дереве  ¹3

int Min_element(BinTreeNode* tree_);// Минимальный элемент в дереве   ¹4

int RepeatEl(BinTreeNode* tree_, int data_);  // Количество повторяющихся элементов в дереве ¹ 5

void Print_List(BinTreeNode* tree_); // Вывод всех листьев дерева ¹6

int Max_Depth(BinTreeNode* tree_); //Максимальная глубина дерева ¹ 10

int Find_Depth(BinTreeNode* tree_, int data_, int depth); // Определяет глубину заданного элемента ¹8

void Sort(int* ar2, BinTreeNode* tree, int k);

void Sorted_BinTree(int* array, BinTreeNode* tree_);

int Num_dep_el(BinTreeNode* tree_, int depth); // Определяет число всех вершин в заданной глубине ¹ 9



