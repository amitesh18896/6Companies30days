// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int start=0;
        int end=0;
        vector<int>ans;
        long long sum=arr[0];
        while(end<n)
        {
          
          if(sum<s)
          {
             end++;
             sum+=arr[end];
          }
          else if(sum==s)
          {
              ans.push_back(start+1);
              ans.push_back(end+1);
              break;
          }
          else
          {
              sum-=arr[start];
              start++;
              if(start>end)
              {
                  end++;
                  sum+=arr[end];
              }
          }
        }
        if(ans.empty())
        {
            ans.push_back(-1);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
