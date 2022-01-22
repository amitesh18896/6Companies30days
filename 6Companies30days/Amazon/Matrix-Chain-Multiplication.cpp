//o(n) solution
//space O(n)
class Solution{
public:
     int dp[101][101];
     int func(int arr[],int i,int j)
     {
         if(i>=j)
         {
             dp[i][j]=0;
         }
         if(dp[i][j]!= -1)
         {
          return dp[i][j];   
         }
         int ans = INT_MAX;
         for(int k=i;k<j;k++)
         {
             int temp = func(arr,i,k)+func(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
             ans=min(ans,temp);
         }
         dp[i][j]=ans;
         return ans;
     }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
         memset(dp,-1,sizeof(dp));
        return func(arr,1,N-1);
    }
};
