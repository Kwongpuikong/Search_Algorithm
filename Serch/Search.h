/*Sequential_Search*/
/*Author: Loapui*/
/*2015.11.10*/

#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>

int Sequential_Search(int L[], int length, int key);
int Binary_Search(int L[], int low, int high, int key, bool recursive = true);
int Interpolation_Search(int L[], int low, int high, int key);

void ErrorMessage(int key);
void SuccessMessage(int key, int i);

#endif