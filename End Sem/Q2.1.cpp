/*Given an integer array A on n elements, the objective is to partition A into two sets A1 and A2 such that PA1 = PA2. i.e., the sum of the elements of A1 equals the sum
of the elements of A2. Present two greedy approaches and compare their performance by taking 100 random arrays of size 30. In 100 random inputs, check how many say YES 
(there is a partition) and NO (there is no partition) for greedy approach 1. Similarly, do the check for greedy approach 2.*/

#include <iostream> // logic 1
#include <string>
using namespace std;

// Return true if there exists a subset of array[0..n) with given sum
bool subsetSum(int arr[], int n, int sum)
{
	// T[i][j] stores true if subset with sum j can be attained with
	// using items up to first i items
	bool T[n + 1][sum + 1];

	// if 0 items in the list and sum is non-zero
	for (int j = 1; j <= sum; j++)
		T[0][j] = false;

	// if sum is zero
	for (int i = 0; i <= n; i++)
		T[i][0] = true;

	// do for ith item
	for (int i = 1; i <= n; i++)
	{
		// consider all sum from 1 to sum
		for (int j = 1; j <= sum; j++)
		{
			// don't include ith element if j-arr[i-1] is negative
			if (arr[i - 1] > j)
				T[i][j] = T[i - 1][j];
			else
			// find subset with sum j by excluding or including the ith item
				T[i][j] = T[i - 1][j] || T[i - 1][j - arr[i - 1]];
		}
	}

	// return maximum value
	return T[n][sum];
}

// Partition problem - Return true if given array arr[0..n-1] can
// be divided into two subsets with equal sum
bool partition(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	// return true if sum is even and array can can be divided into
	// two subsets with equal sum
	return !(sum & 1) && subsetSum(arr, n, sum/2);
}

// main function to solve partition problem
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

	int n = 30;

	if (partition(arr, n))
		cout << "Yes";
	else
		cout << "No";


	return 0;
}