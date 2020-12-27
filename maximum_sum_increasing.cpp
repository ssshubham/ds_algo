#include <iostream>
#include <algorithm>

using namespace std;

/*
Maximum Sum Increasing subsequence problem
{3,20,4,6,7,30} --> {3,20,30} --> maximum sum = 53

Naive approach is to generate all subsequences and then find the maximum sum , T(x) = exponential

Using dynamic programming 
Save lis of each index in a separate array, for every element calculate maximum lis and add element
Then calculate maximum lis from all array points

*/

int main() {
	int arr[] = {3,20,4,6,7,30};
	int n=sizeof(arr)/sizeof(int);
	int msis[n];
	msis[0]=arr[0];
	
	for(int i=1;i<n;i++) {
		msis[i]=arr[i];
		for(int j=0;j<i;j++) {
			if(arr[j]<=arr[i]) {
				msis[i]=max(msis[j]+arr[i], msis[i]);
			}
		}
	}
	int res=msis[0];
	for(int i=1;i<n;i++) {
		res = max(res,msis[i]);
	}
	cout << "Maximum increasing subsequence is = " << res << "\n";
	return 0;
}
