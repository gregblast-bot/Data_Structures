#include <iostream>

using namespace std;

const int MAX_SIZE = 100000;

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
		if(theArray[first1] = theArray[first1])
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
		int mid = first + (last - first) /2;
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
			theArray[loc] = theArray[loc -1];
			loc--;
		}
		
		theArray[loc] = nextItem;
	} 
}
		
