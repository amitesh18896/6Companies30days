//O(n) approach
//Question link: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    // Code here
		    int m[26]={0};
		    queue<char>q;
		    for(int i=0;i<s.length();i++)
		    {
		        m[s[i]-'a']++;
		        if(m[s[i]-'a']==1)
		        {
		            q.push(s[i]);
		        }
		        while(!q.empty() && m[q.front()-'a']!=1)
		        {
		            q.pop();
		        }
		        if(q.empty())
		        {
		            s[i]='#';
		        }
		        else
		        {
		            s[i]=q.front();
		        }
		    }
		    return s;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
