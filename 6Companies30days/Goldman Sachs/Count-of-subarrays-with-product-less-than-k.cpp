// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//O(N)

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int left=0;
        int right=0;
        int ans=0;
        long long prod=1;
        while(right<n)
        {
            prod*=a[right];
            if(prod>=k)
            {
                while(left<=right && prod>=k)
                {
                    prod/=a[left];
                    left++;
                }
            }
         // number of contigous arrays after adding elment a[i] to previous window
            ans+=right-left+1;
            right++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends
