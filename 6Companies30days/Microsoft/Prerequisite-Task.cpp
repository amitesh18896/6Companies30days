//Question link  : https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
     bool dfs(int course,vector<bool>& visited,vector<bool>& inPath,vector<vector<int>>& adj)
    {
        visited[course]=true;
        inPath[course]=true;
        for(auto c:adj[course])
        {
            //if it has a cycle
            if(inPath[c]) //return false saying that we can't complete courses
                return false;
            if(!visited[c] && !dfs(c,visited,inPath,adj))//return false as we cant complete the courses
                return false;
        }
        inPath[course]=false;
		//we can complete the courses so return true
        return true;
    }
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    //detect a cycle in directed graph
        int  n =N;
        
        //create a adjaceny list 
        vector<vector<int>> adj(n);
        for(int i=0;i<pre.size();i++)
        {
            //push all the courses you should finish to complete the current course
            adj[pre[i].first].push_back(pre[i].second);
        }
        
        vector<bool> visited(n,false);
        vector<bool> inPath(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i] && !dfs(i,visited,inPath,adj))
                    return false;
        }
        return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
