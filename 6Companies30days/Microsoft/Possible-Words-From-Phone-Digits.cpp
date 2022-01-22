//Question link : https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/#
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void solve(int i,string res,unordered_map<int,string> hmap,int a[],int N,vector<string> &ans){
        //base case we have made our word , push it in answer and continue
        if(i>=N)
        {
            ans.push_back(res);
            return;
        }
        //get the index, and array number from that index example {2,3,4} get 2 from index 0
        int key = a[i];
        //traverse through all the letter of the word (example abc)
        for(char ch:hmap[key]){
            res += ch;
            solve(i+1,res,hmap,a,N,ans);
            //once traversed pop it out to chek other value
            res.pop_back();
        }
    }   
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        unordered_map<int,string> hmap;
        hmap[1] = "";
        hmap[2] = "abc";
        hmap[3] = "def";
        hmap[4] = "ghi";
        hmap[5] = "jkl";
        hmap[6] = "mno";
        hmap[7] = "pqrs";
        hmap[8] = "tuv";
        hmap[9] = "wxyz";
        hmap[10] = "*";
        hmap[11] = "0";
        hmap[12] = "#";
        string res = "";
        vector<string> ans;
        solve(0,res,hmap,a,N,ans);
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends
