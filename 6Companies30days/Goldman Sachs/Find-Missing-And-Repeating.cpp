// Time - O(n)
// space- O(1)
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{

// Traverse the array. While traversing, use the absolute value of every element as an index and
// make the value at this index as negative to mark it visited. If something is already marked negative then this is the repeating element. 
// To find missing, traverse the array again and look for a positive value.

public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int* ans = (int*)malloc(sizeof(int)*2);
        
        for(int i=0;i<n;i++)
        {
            if(arr[abs(arr[i])-1]<=0)
            {
                ans[0]=abs(arr[i]);
            }
            else
            {
                arr[abs(arr[i])-1] *=-1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                ans[1]=i+1;
                break;
;            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends


//O(nlogn) 
// O(nlogn)
Class Solution:
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int* ans = (int*)malloc(sizeof(int)*2);
        sort(arr,arr+n);
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]==arr[i+1])
            {
                ans[0]=arr[i];
                break;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(binary_search(arr,arr+n,i))
            {
                continue;
            }
            else
            {
                ans[1]=i;
                break;
            }
        }
        return ans;
    }
};
