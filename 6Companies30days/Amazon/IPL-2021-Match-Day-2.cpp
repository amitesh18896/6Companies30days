//variant of sliding window maximum leetcode-239

//optimized approach using list
//keep the maximum of each subrray while changing the window
//every element is add or removed once so O(n)
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        list<int>l;
        vector<int>ans;
        int j=0,i=0;
        while(j<n)
        {
            //while shifting the window by one do this
            while(!l.empty() && l.back()<arr[j])
            {
                l.pop_back(); //remove all smaller elements in the list when the inserted element is greatee than them
            }
            l.push_back(arr[j]);
            //check size of window
            if(j-i+1<k)
            {
                //if size is less then k increase j;
                j++;
            }
            //size =k
            else if(j-i+1==k)
            {
                //front of list contains the answer(max possible of a window)
                ans.push_back(l.front());
                //after pushing that into answer pop the element out of list as it is of no use now
                if(arr[i]==l.front())
                {
                    l.pop_front();
                }
                //move i and j
                i++;
                j++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends

//naive approach
//O(N*k)
void printKMax(int arr[], int n, int k) 
{ 
    int j, max; 

    for (int i = 0; i <= n - k; i++) 
    { 
        max = arr[i]; 

        for (j = 1; j < k; j++) 
        { 
            if (arr[i + j] > max) 
                max = arr[i + j]; 
        } 
        cout << max << " "; 
    } 
} 
