// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        for(int i=0;i<s.length();i++)
        {
            if(isupper(s[i]))
            {
                s[i]=tolower(s[i]);
                if(i!=0)
                {
                    s.insert(i," ");
                }
            }
        }
        return s;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends
