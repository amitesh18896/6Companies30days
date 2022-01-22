// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
string inttobinary(int n)
{
    string ans="";
    while(n>0)
    {
        ans=to_string(n%2)+ans;
        n=n/2;
    }
    return ans;
}
vector<string> generate(int n)
{
	// Your code here
	vector<string>ans;
	for(int i=1;i<=n;i++)
	{
	    ans.push_back(inttobinary(i));
	}
	return ans;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
