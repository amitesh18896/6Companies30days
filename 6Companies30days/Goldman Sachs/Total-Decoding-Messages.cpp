// Question: Total Decoding Messages
// Question Link: https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1
// Time Complexity: O(n)
// Space Complexity: O(n)

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	 const int MOD = 1e9+7;
	 long long dp[10004];
	 int getcount(string str,int n)
	 {
	     if(str[0]=='0' || str[0]==' ')
	     {
	         return 0;
	     }
	     // reached the first character of the string ( n=0 or n=1) so there is only 1 way to manupulate it	  
	     if(n==0 || n==1)
	     {
	         return 1;
	     }
	     if(dp[n]!=-1)
	     {
	         return dp[n]%MOD;
	     }
	     int count=0;
	     //last character of string is >0 so keep count of ways to mapuluate the left n-1 characters
	     if(str[n-1]>'0')
	     {
	         count = getcount(str,n-1)%MOD;
	     }
	     // if 2nd last char = 20 to 26 or 11 to 19 then keep calculating ways to manupulate the left n-2 characters
	     if(str[n-2]=='1' || (str[n-2]=='2' && str[n-1]<'7'))
	     {
	         count = (count%MOD + getcount(str,n-2)%MOD)%MOD;
	     }
	    //store that in dp[n] and return it
	     return dp[n]=count%MOD;
	 }
		int CountWays(string str){
		    // Code here
		    int n = str.size();
		    memset(dp,-1,sizeof dp);
		    return getcount(str,n)%MOD;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends


//O(n)
Class solution {	
public:
		int CountWays(string str){
		    // Code here
		    int n=str.length();
		    long long dp[n+1];
		    dp[0]=1;
		    dp[1]=1;
		    if(str[0]=='0')
		    {
		        return 0;
		    }
		    long long mod=1e9+7;
		    for(int i=2;i<=n;i++)
		    {
		        dp[i]=0;
		        if(str[i-1]>'0')
		        {
		            dp[i]=dp[i-1];
		        }
		        int b=(str[i-2]-'0')*10+(str[i-1]-'0');
		        if(10<=b && b<=26)
		        {
		            dp[i]=(dp[i]%mod+dp[i-2]%mod)%mod;
		        }
		        if(b==0)
		        {
		            return 0;
		        }
		    }
		    return (int)dp[n];
		}

};
