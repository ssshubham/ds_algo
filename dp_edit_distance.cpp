#include <iostream>
# include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int maximum = 1000;

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
*/
/*
int minSteps(string s1, string s2, int m, int n) {

    if(n==0)
        return m;
    if(m==0)
        return n;
    //if characters are equal 
    if(s1[m]==s2[n]) {
        return minSteps(s1, s2, m-1, n-1);
    }
    // if characters are unequal 
    else {
        // calling minSteps for insert, delete and replace respectively
        return 1 + min({ minSteps(s1, s2, m, n-1) , minSteps(s1,s2,m-1,n) , minSteps(s1,s2,m-1,n-1) });
    }
    

}
*/

int minSteps(string s1, string s2, int m, int n, int a[][maximum]) {

	// if second string is empty then only option is to delete all characters
	if(n==0)
	{
		return m;
	}
    // if first string is empty then only option is to insert all elements
    if(m==0)
    {
    	return n;
	}
	
	// if it is already calculated, return from here
	if(a[m-1][n-1] != -1)
		return a[m-1][n-1];

	//if characters are equal 
    if(s1[m-1]==s2[n-1]) {
        return a[m-1][n-1] = minSteps(s1, s2, m-1, n-1,a);
    }
    // if characters are unequal 
    else {
        // calling minSteps for insert, delete and replace respectively
        return a[m-1][n-1] = 1 + min({ minSteps(s1, s2, m, n-1,a) , minSteps(s1,s2,m-1,n,a) , minSteps(s1,s2,m-1,n-1,a) });
    }	
}

int main() {

    int m,n;
    string s1,s2;
    cout << "Enter string s1 and s2 \n";
    cin >> s1 >> s2;
    m = s1.length();
    n = s2.length();
    int a[m][maximum];
    memset(a, -1, sizeof a);
//    for(int i=0;i<m;i++)
//    {
//    	for(int j=0;j<n;j++)
//    		cout << a[i][j] << " ";
//    	cout << "\n";
//	}
    cout << "Minimum steps required are: " <<  minSteps(s1,s2,m,n,a)<< "\n";
    return 0;
}
