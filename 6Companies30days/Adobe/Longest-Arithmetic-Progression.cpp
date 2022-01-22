// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        vector<vector<int>>dp(n,vector<int>(10000,1));
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i][A[i]-A[j]]=dp[j][A[i]-A[j]]+1;
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<10000;j++)
            {
                if(dp[i][j]>maxi)
                {
                    maxi=dp[i][j];
                }
            }
        }
        return maxi;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
