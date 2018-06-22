/*
*	Program Title: Binary Exponentiation	
*	Author: Utkal Sinha
*	
*	This program computes x^y in O(log y) time complexity
*/

#include <bits/stdc++.h>
using namespace std;

int getPow(int x, int y) {
	int res = 1;
	while(y>0){
		/*
			If y is odd, we are moving towards x * x^(y - 1)
		*/
		if(y&1) res = res * x;
		
		/*
			y is even now. So we are reducing x^y to x^(y/2) * x^(y/2)
		*/
		x = x*x;
		y = y>>1;
	}
	return res;
}

int main() {
	int  ans = getPow(2,5);
	cout<<ans<<endl;
	return 0;
}
