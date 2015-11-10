/*Search*/
/*Author: Loapui*/
/*2015.11.10*/

#include "Search.h"

void SuccessMessage(int key, int i){

	std::cout << "The " << key << " is NO." << i << " number" << std::endl;
}

void ErrorMessage(int key){

	std::cout << "NO " << key << " in the List" << std::endl;
}

int Sequential_Search(int L[], int length, int key){

	L[0] = key; // ÉèÖÃÉÚ±ø
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