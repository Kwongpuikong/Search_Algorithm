/*Search*/
/*Author: Loapui*/
/*2015.11.10*/

/*完成二叉查找树*/
/*2015.11.11*/

#include "Search.h"

void SuccessMessage(int key, int i){

	std::cout << "The " << key << " is NO." << i << " number" << std::endl;
}

void ErrorMessage(int key){

	std::cout << "NO " << key << " in the List" << std::endl;
}

int Sequential_Search(int L[], int length, int key){

	L[0] = key; // 设置哨兵
	int i = length;
	while (i > 0){
	
		if (L[i] == key)
			break;
		else
			i--;
	}
	if (i != 0){
		SuccessMessage(key, i);
		return i;
	}
	else{
		ErrorMessage(key);
		return -1;
	}
}

int Binary_Search(int L[], int low, int high, int key, bool recursive){

	if (!recursive){
	
		while (low <= high){

			int mid = (low + high) / 2;
			if (L[mid] == key){
			
				SuccessMessage(key, mid);
				return mid;
			}
			else if (L[mid] > key){

				high = mid - 1;
			}
			else{

				low = mid + 1;
			}
		}
		ErrorMessage(key);
		return -1;
	}
	else{

		if (low <= high){
		
			int mid = (low + high) / 2;
			if (L[mid] == key){
			
				SuccessMessage(key, mid);
				return mid;
			}
			else if (L[mid] > key){
			
				high = mid - 1;
				Binary_Search(L, low, high, key);
			}
			else{
			
				low = mid + 1;
				Binary_Search(L, low, high, key);
			}
		}
		else{
		
			ErrorMessage(key);
			return -1;
		}
	}
}

int Interpolation_Search(int L[], int low, int high, int key){

	int mid;
	while (low <= high){
	
		mid = low + ((key - L[low]) / (L[high] - L[low])) * (high - low);
		if (L[mid] == key){
		
			SuccessMessage(key, mid);
			return mid;
		}
		else if (L[mid] > key){

			high = mid - 1;
		}
		else{
		
			low = mid + 1;
		}
	}
	ErrorMessage(key);
	return -1;
}

int Fibonacci(int x){

	if (x == 1 || x == 2){
	
		return 1;
	}
	else{
	
		return Fibonacci(x - 2) + Fibonacci(x - 1);
	}
}

int Fibonacci_Search(int L[], int low, int high, int key){

	int n = high - low + 1;
	int k = 1;
	while (Fibonacci(k)-1 < n){
	
		k++;
	}
	// 补全不满的位置
	for (int i = high + 1; i <= Fibonacci(k)-1; i++){
	
		L[i] = L[high];
	}

	int mid;
	while (low <= high){
	
		mid = low + Fibonacci(k - 1) - 1;
		if (L[mid] == key){

			// std::cout << "mid = " << mid << std::endl;
		
			if (mid <= high){
			
				SuccessMessage(key, mid);
				return mid;
			}
			else{
			
				SuccessMessage(key, high);
				return high;
			}

		}
		else if (L[mid] > key){
		
			high = mid - 1;
			k -= 1;
		}
		else if (L[mid] < key){
		
			low = mid + 1;
			k -= 2;
		}
	}
	ErrorMessage(key);
	return -1;

}

bool BST_Search(BiTree T, int key, BiTree parent, BiTree* res){

	if (!T){

		*res = parent;
		return false;
	}
	else if (T->data == key){
	
		*res = T;
		return true;
	}
	else if (T->data < key){

		BST_Search(T->rchild, key, T, res);
	}
	else{
	
		BST_Search(T->lchild, key, T, res);
	}

}

bool BST_Insert(BiTree* T, int key){

	BiTree lst;
	if (!BST_Search(*T, key, NULL, &lst)){

		BiTree p = (BiTree)malloc(sizeof(BiTNode));
		if (!p){
			
			std::cout << "Out of Memory!!!" << std::endl;
			return false;
		}
		else{

			p->data = key;
			p->lchild = NULL;
			p->rchild = NULL;
		}

		if (!lst){
		
			*T = p;
		}
		else if (lst->data < key)
				lst->rchild = p;
		else
				lst->lchild = p;
		return true;
	}
	else
		return false;
}

bool BST_Construct(int L[], int length, BiTree *T){

	for (int i = 1; i <= length; i++){
	
		if (!BST_Insert(T, L[i]))
			return false;
	}
	return true;
}

void SearchBST(BiTree* T, int key){

	BiTree lst;
	bool flag = BST_Search(*T, key, NULL, &lst);
	if (!flag){
	
		ErrorMessage(key);
		BST_Insert(T, key);
		std::cout << "Finish Inserting." << std::endl;
	}
	else{
	
		std::cout << "p->data = " << lst->data << std::endl;
	}
}

bool BST_Delete(BiTree *T, int key){

	if (!(*T))
		return false;
	else if ((*T)->data == key){
	
		return Delete(T);
	}
	else if ((*T)->data < key){

		return BST_Delete(&(*T)->rchild, key);
	}
	else
		return BST_Delete(&(*T)->lchild, key);

}

bool Delete(BiTree *p){

	BiTree ptr, s;

	if (!(*p)->lchild){

		ptr = (*p);
		*p = (*p)->rchild;
		free(ptr);
	}
	else if (!(*p)->lchild){
	
		ptr = *p;
		*p = (*p)->rchild;
		free(ptr);
	}
	else{
		
		ptr = *p;
		s = ptr->lchild;
		while (s->rchild){

			ptr = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if (ptr != (*p))
			ptr->rchild = s->lchild;
		else
			ptr->lchild = s->lchild;

		// Important.
		free(s);
	}
	return true;

}

int BST_Max(BiTree T){

	BiTree p = NULL;
	if (T)
		p = T->rchild;
	while (p->rchild){
	
		p = p->rchild;
	}
	return p->data;

}

int BST_Min(BiTree T){

	BiTree p = NULL;
	if (T)
		p = T->lchild;
	while (p->lchild){
	
		p = p->lchild;
	}
	return p->data;
}