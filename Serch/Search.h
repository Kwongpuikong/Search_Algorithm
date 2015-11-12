/*Sequential_Search*/
/*Author: Loapui*/
/*2015.11.10*/

/*完成二叉查找树*/
/*2015.11.11*/

/*完成哈希表*/
/*2015.11.12*/

#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>

/*二叉树结点*/
typedef struct BiTNode{

	int data;
	BiTNode *lchild, *rchild;
}BiTnode, *BiTree;

/*哈希表结构*/
typedef struct HashTable{

	int *table;
	int compacity = 11;
	int count = 0;
}HashTable;

#define NULLKEY -32768

int Sequential_Search(int L[], int length, int key);
int Binary_Search(int L[], int low, int high, int key, bool recursive = true);
int Interpolation_Search(int L[], int low, int high, int key);
int Fibonacci_Search(int L[], int low, int high, int key);

/*利用二叉查找树查找关键字*/
bool BST_Search(BiTree T, int key, BiTree parent, BiTree* res);
bool BST_Insert(BiTree* T, int key);
void SearchBST(BiTree* T, int key);

/*删除二叉查找树结点*/
bool BST_Delete(BiTree* T, int key);
bool Delete(BiTree* T);

/*构建二叉查找树*/
bool BST_Construct(int L[],int length, BiTree *T);

/*利用二叉查找树得最大最小值*/
int BST_Max(BiTree T);
int BST_Min(BiTree T);

/*哈希表初始化*/
bool InitHashTable(HashTable* H);

/*哈希表查找*/
int Hash(int key, int HashTable_Compacity);
bool Hash_Search(HashTable* H, int key, int* index);

/*哈希表插入*/
bool Hash_Insert(HashTable* H, int key);

/*哈希表删除*/
bool Hash_Delete(HashTable* H, int key);



int Fibonacci(int x);
void ErrorMessage(int key);
void SuccessMessage(int key, int i);

#endif