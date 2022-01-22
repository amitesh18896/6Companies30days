//recursion
class Solution{
    public:
    int helper(int n,int x,int num,vector<int>&dp)
    {
        int temp=pow(num,x);
        if(dp[n]>0)
        {
            return dp[n];
        }
        if(n==temp)
        {
            return 1;
        }
        if(temp>n)
        {
            return 0;
        }
        int a = helper(n-temp,x,num+1);
        int b = helper(n,x,num+1);
        return dp[n]= a+b;
    }
    int numOfWays(int n, int x)
    {
        // code here
        vector<int>dp(n,-1);
        helper(n,x,1,dp);
    }
};

//dp -> wrong output
class Solution{
    public:
    int helper(int n,int x,int num, vector<vector<int>>&dp)
    {
        int temp=pow(num,x);
        if(dp[n][num]!=-1)
        {
            return dp[n][num];
        }
        if(n==temp)
        {
            return dp[n][num]=1;
        }
        if(temp>n)
        {
            return dp[n][num]=0;
        }
        int a = helper(n-temp,x,num+1,dp);
        int b = helper(n,x,num+1,dp);
        return dp[n][num]= a+b;
    }
    int numOfWays(int n, int x)
    {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(pow(n,1.0/x)+1,-1));
        
        return helper(n,x,1,dp);
    }
};
