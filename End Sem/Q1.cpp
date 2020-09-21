/*Quick-sort variant; Perform quick sort with 2 pivot elements. Choose the first and last elements as pivots, say a and b. At the end of the first pass, the input array consists of
elements less than or equal to a, the elements between a and b, and the elements greater than or equal to b. Do this recursively to obtain a sorted sequence. You may have to sort elements between a and b
at each iteration.*/

#include<iostream>
using namespace std;

void swap(int* a, int* b);
int partition (int arr[], int start, int end, int *leftpvt); 
void quickSort(int arr[], int start, int end);

int main()
{
	int n;
	cout << "Enter the no of elements you want to enter in a array : " ;
	cin >> n;
	cout << endl << "Enter the elements in an array : ";
	int arr[n];
	int i;
	for(i=0;i<n;i++)
	{
		cin >> arr[i];
	}

	cout << "The given array in sorted order is : ";
	quickSort(arr,0,n-1);

	for(i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	
	return 0;
}

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
int partition (int arr[], int start, int end, int *leftpvt)  
{  
     if (arr[start] > arr[end])  
        swap(&arr[start], &arr[end]);  
      
    // p is the left pivot, and q is the right pivot.  
    int j = start + 1;  
    int g = end - 1, k = start + 1, p = arr[start], q = arr[end];  
    while (k <= g)  
    {  
  
        // if elements are less than the left pivot  
        if (arr[k] < p)  
        {  
            swap(&arr[k], &arr[j]);  
            j++;  
        }  
  
        // if elements are greater than or equal  
        // to the right pivot  
        else if (arr[k] >= q)  
        {  
            while (arr[g] > q && k < g)  
                g--;  
            swap(&arr[k], &arr[g]);  
            g--;  
            if (arr[k] < p) 
            {  
                swap(&arr[k], &arr[j]);  
                j++;  
            }  
        }  
        k++;  
    }  
    j--;  
    g++;  
  
    // bring pivots to their appropriate positions.  
    swap(&arr[start], &arr[j]);  
    swap(&arr[end], &arr[g]);  
  
    // returning the indices of the pivots.  
    *leftpvt = j;
  
    return g;  
}  
  
void quickSort(int arr[], int start, int end)  
{  
    if (start < end)  
    {  
        // leftpvt means left pivot, and rightpvt means right pivot.  
        int leftpvt, rightpvt;  
        rightpvt = partition(arr, start, end, &leftpvt);  
        quickSort(arr, start, leftpvt - 1);  
        quickSort(arr, leftpvt + 1, rightpvt - 1);  
        quickSort(arr, rightpvt + 1, end);  
    }  
}  
  