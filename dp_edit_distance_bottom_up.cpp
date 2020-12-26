#include <iostream>
# include <string>
#include <algorithm>
#include <cstring>
using namespace std;

/*
Convert S1 to S2 using only 3 operations:
1. Insert
2. Delete
3. Replace

e.g. 
1.  SATURDAY
    SUNDAY

O/P: 3

2.  CUT
    CAT

O/p: 1
*/

/*
Recursive Approach: Compare last characters of both strings. If they are equal then move to next character. If they are unequal, then 
there can be 3 operations possible: insert, delete or replace.
SATURDAY --> SATUR --> (1) SATURN (2) SATU (3) SATUN
SUNDAY   --> SUN   -->     SUN        SUN      SUN

Optimized Top down approach 
    C  A  T
  0 1  2  3
C 1 0  1  2
U 2 1  1  2
T 3 2  2  1
*/

int minSteps(string s1, string s2, int m, int n) {

	int a[m+1][n+1];
	//filling first column by 0,1,2,3,4 etc
	for(int i=0;i<m;i++)
	{
		a[i][0]=i;
	}
	//filling first row by 0,1,2,3,4 etc
	for(int i=0;i<n;i++)
	{
		a[0][i]=i;
	}

	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			if(s1[i-1] == s2[j-1]) {
				a[i][j]=a[i-1][j-1];
			}	
			else {
				a[i][j]=1+min({a[i-1][j],a[i-1][j-1],a[i][j-1]});
			}
		}
	}
	return a[m][n];
}

int main() {

    int m,n;
    string s1,s2;
    cout << "Enter string s1 and s2 \n";
    cin >> s1 >> s2;
    m = s1.length();
    n = s2.length();
    cout << "Minimum steps required are: " <<  minSteps(s1,s2,m,n)<< "\n";
    return 0;
}
