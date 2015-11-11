/*Sequential_Search*/
/*Author: Loapui*/
/*2015.11.10*/

/*��ɶ��������*/
/*2015.11.11*/

#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>

typedef struct BiTNode{

	int data;
	BiTNode *lchild, *rchild;
}BiTnode, *BiTree;

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

int Fibonacci(int x);
void ErrorMessage(int key);
void SuccessMessage(int key, int i);

#endif