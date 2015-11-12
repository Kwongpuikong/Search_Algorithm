/*Sequential_Search*/
/*Author: Loapui*/
/*2015.11.10*/

/*��ɶ��������*/
/*2015.11.11*/

/*��ɹ�ϣ��*/
/*2015.11.12*/

#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>

/*���������*/
typedef struct BiTNode{

	int data;
	BiTNode *lchild, *rchild;
}BiTnode, *BiTree;

/*��ϣ��ṹ*/
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

/*���ö�����������ҹؼ���*/
bool BST_Search(BiTree T, int key, BiTree parent, BiTree* res);
bool BST_Insert(BiTree* T, int key);
void SearchBST(BiTree* T, int key);

/*ɾ��������������*/
bool BST_Delete(BiTree* T, int key);
bool Delete(BiTree* T);

/*�������������*/
bool BST_Construct(int L[],int length, BiTree *T);

/*���ö���������������Сֵ*/
int BST_Max(BiTree T);
int BST_Min(BiTree T);

/*��ϣ���ʼ��*/
bool InitHashTable(HashTable* H);

/*��ϣ�����*/
int Hash(int key, int HashTable_Compacity);
bool Hash_Search(HashTable* H, int key, int* index);

/*��ϣ�����*/
bool Hash_Insert(HashTable* H, int key);

/*��ϣ��ɾ��*/
bool Hash_Delete(HashTable* H, int key);



int Fibonacci(int x);
void ErrorMessage(int key);
void SuccessMessage(int key, int i);

#endif