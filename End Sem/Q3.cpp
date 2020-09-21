// Given a finite set, write an algorithm to list all ternary relations. Also, display the count.

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MAX INT_MAX
#define MOD 1000000007
#define dd double

void printTernaryRel(vector<int> arr);
void subset(vector<vector<int>> ternary_product,vector<bool> b,int n,int i,int &count);

int main()
{
	int n;
	cout<<"Enter the number of elements in the set : ";
	cin>>n;

	cout<<"Enter the elements of the set : ";
	vector<int> arr(n);
	for(int i=0;i<n;++i)
		cin>>arr[i];

	printTernaryRel(arr);
}

void printTernaryRel(vector<int> arr)
{
	// First lets calculate the all ternary cartesian products of the given set.
	int n = arr.size(),p=0;
	vector<vector<int>> ternary_pdt(pow(n,3),vector<int> (3,0));
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			for(int k=0;k<n;++k)
			{
				ternary_pdt[p][0] = arr[i];
				ternary_pdt[p][1] = arr[j];
				ternary_pdt[p++][2] = arr[k];
			}
		}
	}

	// To find all ternary relations, we have to list all possible subsets of the ternary_product
	int size = pow(n,3);
	// Initialize a dummy array to zero indicating none of the elements are included in the subset
	vector<bool> b(size,0);
	int count=0;
	subset(ternary_pdt,b,size,0,count);
	cout <<"Number of ternary relations are: "<<count<<endl;
}

void subset(vector<vector<int>> ternary_pdt,vector<bool> b,int n,int i,int &count)
{
	if(i<n)
	{
		//Exclude ith element and find subset
		b[i] =0;
		subset(ternary_pdt,b,n,i+1,count);

		//Include ith element and find the subset
		b[i] =1;
		subset(ternary_pdt,b,n,i+1,count);
	}
	else if(i == n)
	{
		// Print the subset
		++count;
		cout << "{";
		for(int j=0;j<n;++j)
		{
			if(b[j] == 1)
				cout<<"("<<ternary_pdt[j][0]<<","<<ternary_pdt[j][1]<<","<<ternary_pdt[j][2]<<") ";
		}
		cout << "}"<<endl;
	}
}

