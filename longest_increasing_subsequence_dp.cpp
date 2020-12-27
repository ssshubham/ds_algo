#include <iostream>
#include <algorithm>

using namespace std;

/*
Longest Increasing subsequence problem
{10,5,18,7,2,9} --> {5,7,9} --> length will be 3

Naive approach is to generate all subsequences and then find the maximum length , T(x) = exponential

Using dynamic programming 
Save lis of each index in a separate array, for every element calculate maximum lis and add 1
Then calculate maximum lis from all array points

*/

int main() {
	int arr[] = {10,5,18,7,2,9};
	int n=sizeof(arr)/sizeof(int);
	int lis[n];
	lis[0]=1;
	
	for(int i=1;i<n;i++) {
		lis[i]=1;
		for(int j=0;j<i;j++) {
			if(arr[j]<=arr[i]) {
				lis[i]=max(lis[j]+1, lis[i]);
			}
		}
	}
	int res=0;
	for(int i=0;i<n;i++) {
		res = max(res,lis[i]);
	}
	cout << "Maximum increasing subsequence is = " << res << "\n";
	return 0;
}
