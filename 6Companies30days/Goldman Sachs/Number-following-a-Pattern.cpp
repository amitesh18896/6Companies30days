// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

//push index+1(unique) in stack till you get a 'I'
// when I occurs in string , pop the elements of stack thus the resulting string is in descending order, thus the next index in the stack pushed with be in increasing order.
 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        stack<int>st;
        string ans="";
        for(int i=0;i<=S.length();i++)
        {
            st.push(i+1);
            if(i==S.length() || S[i]=='I')
            {
                while(!st.empty())
                {
                    ans+=to_string(st.top());
                    st.pop();
                }
            }
        }
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
