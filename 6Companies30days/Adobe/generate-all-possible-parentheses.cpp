// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void helper(int totalopen,int open,string res,vector<string>&ans)
    {
        if(totalopen==0 && open==0)
        {
            ans.push_back(res);
            return ;
        }
        if(totalopen>0)
        {
            helper(totalopen-1,open+1,res+"(",ans);
        }
        if(open>0)
        {
            helper(totalopen,open-1,res+")",ans);
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string>ans;
        helper(n,0,"",ans);
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
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends
