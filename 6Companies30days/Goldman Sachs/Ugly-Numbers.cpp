// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    ull dp[n+1];
	    dp[1]=1;
	    //all pointers point to position 1
	    ull pointer2=1;
	    ull pointer3=1;
	    ull pointer5=1;
	    for(int i=2;i<=n;i++)
	    {
	        //take minimum of factors of 2,3,5
	        ull factor1 = 2*dp[pointer2];
	        ull factor2 = 3*dp[pointer3];
	        ull factor3 = 5*dp[pointer5];
	        ull minimum_of_factors = min(factor1,min(factor2,factor3));
	        dp[i] = minimum_of_factors;
	        //move the pointer which points to the minimum factor
	        if(minimum_of_factors==factor1)
	        {
	            pointer2++;
	        }
	        if(minimum_of_factors==factor2)
	        {
	            pointer3++;
	        }
	        if(minimum_of_factors==factor3)
	        {
	            pointer5++;
	        }
	    }
	    return dp[n];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends


//other method
