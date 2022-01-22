// Question: Partition Equal Subset Sum 
// Question Link: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        int sum=0;
        for(int i=0; i<n; ++i)
            sum += arr[i];
        if (sum&1)
            return false;
        int w = sum/2;
        
        bool dp[n][w+1];
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<=w; ++j)
            {
                if(j==0)
                    dp[i][j] = true;
                else if(arr[i] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];
            }
        }
        return dp[n-1][w];
    }
};
