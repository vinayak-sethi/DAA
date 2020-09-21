// C++ program to split an array into Two equal sum subarrays 
#include<bits/stdc++.h> // logic 2
using namespace std; 

int findSplitPoint(int arr[], int n) 
{ 
	// traverse array element and compute sum of whole array 
	int leftSum = 0; 
	for (int i = 0 ; i < n ; i++) 
		leftSum += arr[i]; 

	// again traverse array and compute right sum 
	// and also check left_sum equal to right 
	// sum or not 
	int rightSum = 0; 
	for (int i=n-1; i >= 0; i--) 
	{ 
		// add current element to right_sum 
		rightSum += arr[i]; 

		// exclude current element to the left_sum 
		leftSum -= arr[i] ; 

		if (rightSum == leftSum) 
			return i ; 
	} 

	// if it is not possible to split array 
	// into two parts. 
	return -1; 
} 

// Prints two parts after finding split point using 
// findSplitPoint() 
void printTwoParts(int arr[], int n) 
{ 
	int splitPoint = findSplitPoint(arr, n); 

	if (splitPoint == -1 || splitPoint == n ) 
	{ 
		cout << endl << "Not Possible" <<endl; 
		return; 
	} 
	for (int i = 0; i < n; i++) 
	{ 
		if(splitPoint == i) 
			cout << endl; 
		cout << arr[i] << " " ; 
	} 
} 

int main()
{
	srand (time(0));
	int arr[30];
	int i;
	for(i=0;i<30;i++)
	{
		arr[i] = (rand() % 30) + 1;
	}

	cout << "Given array is : ";
	{
		for(i=0;i<30;i++)
		{
			cout << arr[i] << " ";
		}
	}

	cout << endl;
	int n = 30;
	printTwoParts(arr, n); 

	return 0;
}