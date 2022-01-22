//not a good way
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
         string temp="";
        while(n>0){
            char ch='A'+(n-1)%26;
            temp=ch+temp;
            n=(n-1)/26;
        }
        return temp;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends


// good method - > tc = log(n) base: (26)
void printString(int n)
{
char str[MAX]; // To store result (Excel column name)
int i = 0; // To store current index in str which is result

while (n > 0) {
// Find remainder
int rem = n % 26;

// If remainder is 0, then a 'Z' must be there in output
if (rem == 0) {
str[i++] = 'Z';
n = (n / 26) - 1;
}
else // If remainder is non-zero
{
str[i++] = (rem - 1) + 'A';
n = n / 26;
}
}
str[i] = '\0';

// Reverse the string and print result
reverse(str, str + strlen(str));
cout << str << endl;

return;
}
