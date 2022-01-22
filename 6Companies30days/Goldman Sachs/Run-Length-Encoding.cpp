//Method 1
//O(n) approx
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends

string encode(string src)
{     
  //Your code here 
  string ans="";
  int left=0,right=0;
  while(right<src.length())
  {
      while(src[left]==src[right])
      {
          //increase right counter till elements in the span are equal;
          right++;
      }
      ans+=src[left]+to_string(right-left);
      //move left pointer to the end of the repeating sequence of one element.
      left=right;
  }
  return ans;
}     


//Method 2

