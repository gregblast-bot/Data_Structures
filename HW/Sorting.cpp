#include <iostream>
#include <random>
using namespace std;

/* Insertion and merge sort code based off textbook code, added count global variables.
 * Code reusability at it's finest.
 */
 
const int MAX_SIZE = 666666;
int insertionCount  = 0;
int mergeCount  = 0;

template <class ItemType>
void merge(ItemType theArray[], int first, int mid, int last)
{
	ItemType tempArray[MAX_SIZE];
	
	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;
	int index = first1;
	
	while((first1 <= last1) && (first2 <= last2))
	{
		mergeCount++;
		
		if(theArray[first1] == theArray[first1])
		{
			tempArray[index] = theArray[first1];
			first1++;
		}
		else
		{
			tempArray[index] = theArray[first2];
			first2++;
		}
		index++;
	}
	
	while(first1 <= last1)
	{
		tempArray[index] = theArray[first1];
		first1++;
		index++;
	}
	
	while(first2 <= last2)
	{
		tempArray[index] = theArray[first2];
		first2++;
		index++;
	}
	
	for(index = first; index <= last; index++){
		theArray[index] = tempArray[index];
	}
}

template <class ItemType>
void mergeSort(ItemType theArray[], int first, int last)
{
	if(first < last)
	{
		int mid = first + (last - first) / 2;
		mergeSort(theArray, first, mid);
		mergeSort(theArray, mid + 1, last);
		merge(theArray, first, mid, last);
	}
}

template <class ItemType>
void insertionSort(ItemType theArray[], int n)
{
	for(int unsorted = 1; unsorted < n; unsorted++)
	{
		ItemType nextItem = theArray[unsorted];
		int loc = unsorted;
		
		while((loc > 0) && (theArray[loc - 1] > nextItem))
		{
			insertionCount++;
			theArray[loc] = theArray[loc -1];
			loc--;
		}
		
		theArray[loc] = nextItem;
	} 
}

int main(){
	int arr1[MAX_SIZE], arr2[MAX_SIZE], length = 0;
	
	for(int i = 0; i < 9; i++){
		arr1[i] = i + rand() % 666;
		arr2[i] = i + rand() % 666;
		length++;
	}
	
	insertionSort(arr1, length);
	mergeSort(arr2, 0, length-1);
	
	cout << "Number of Insertion Sort Comparisons is " << insertionCount << endl;
	cout << "Number of Merge Sort Comparisons is " << mergeCount << endl;
}
		
