// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int findMaxCoins(vector<int>&coin, int i, int j, auto &lookup)
{
    // base case: one pot left, only one choice possible
    if (i == j) {
        return coin[i];
    }
 
    // if we are left with only two pots, choose one with maximum coins
    if (i + 1 == j) {
        return max(coin[i], coin[j]);
    }
 
    // if the subproblem is seen for the first time, solve it and
    // store its result in a lookup table
    if (lookup[i][j] == 0)
    {
        // if a player chooses the front pot `i`, the opponent is left to choose
        // from [i+1, j].
        // 1. If the opponent chooses front pot `i+1`, recur for [i+2, j]
        // 2. If the opponent chooses rear pot `j`, recur for [i+1, j-1]
 
        int start = coin[i] + min(findMaxCoins(coin, i + 2, j, lookup),
                                findMaxCoins(coin, i + 1, j - 1, lookup));
 
        // if a player chooses rear pot `j`, the opponent is left to choose
        // from [i, j-1].
        // 1. If the opponent chooses front pot `i`, recur for [i+1, j-1]
        // 2. If the opponent chooses rear pot `j-1`, recur for [i, j-2]
 
        int end = coin[j] + min(findMaxCoins(coin, i + 1, j - 1, lookup),
                        findMaxCoins(coin, i, j - 2, lookup));
 
        // assign a maximum of two choices
        lookup[i][j] = max(start, end);
    }
 
    // return the subproblem solution from the map
    return lookup[i][j];
}
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	      vector<vector<int>> lookup(n + 1, vector<int>(n + 1));
         return findMaxCoins(A, 0, n - 1, lookup);
	    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends
