#include <iostream>
#include <algorithm>

using namespace std;

/*
Maximum length bitonic subsequence problem
{1,11,2,10,4,5,2,1} --> {1,11,10,5,2,1} --> length will be 6
First increasing and then decreasing
{10,5,4,3} --> length will be 4
{1,2,3,4,5,6} --> length will be 6

Naive approach is to generate all subsequences and then find the maximum length , T(x) = exponential

Using dynamic programming 
Calculate lis and lds
Save lis of each index in a separate array, for every element calculate maximum lis and add 1
Then calculate maximum length bitonic subsequence by adding lis[i]+lds[i]-1 , from all array points

*/

int main() {
	int arr[] = {1,11,2,10,4,5,2,1};
	int n=sizeof(arr)/sizeof(int);
	int lis[n];
	int lds[n];
	lis[0]=1;
	
	for(int i=1;i<n;i++) {
		lis[i]=1;
		for(int j=0;j<i;j++) {
			if(arr[j]<=arr[i]) {
				lis[i]=max(lis[j]+1, lis[i]);
			}
		}
	}
	
	lds[n-1]=1;
	
	for(int i=n-2;i>=0;i--) {
		lds[i]=1;
		for(int j=n-1;j>i;j--) {
			if(arr[j]<=arr[i]) {
				lds[i]=max(lds[j]+1, lds[i]);
			}
		}
	}
	
	int res=lis[0]+lds[0];
	for(int i=1;i<n;i++) {
		res = max(res,lis[i]+lds[i]);
	}
	cout << "Maximum increasing subsequence is = " << res-1 << "\n";
	return 0;
}
