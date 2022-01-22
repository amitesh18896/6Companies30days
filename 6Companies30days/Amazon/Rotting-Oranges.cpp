class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        int fresh=0;
        int time=0;
        queue<pair<int,int>>q;
        int n =grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //fresh orange
                if(grid[i][j]!=0)
                {
                    fresh++;
                }
                //rotten organge found
                if(grid[i][j]==2)
                {
                   q.push({i,j});
                }
            }
        }
        
        //directions to move
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        
        while(!q.empty())
        {
            int countrotten=q.size();
            //have to make all orangess rotten , so keep count of rotten oranges
            count+=countrotten;
            //in 1 sec i can rot orranges adjacent to these countrotten oranges
            while(countrotten--)
            {
                int adjacenti = q.front().first;
                int adjacentj = q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                   int ni=adjacenti + dx[i];
                    int nj=adjacentj + dy[i];
                    //check bounds and if there are not any fresh orange in adjacent continue
                    if(ni<0 || nj<0 || ni>=n || nj>=m || grid[ni][nj]!=1)
                    {
                        continue;
                    }
                    //found a fresh organge
                    grid[ni][nj]=2;
                    q.push({ni,nj});
                }
                
            }
            if(!q.empty())
            {
                time++;
            }
        }
        return fresh==count?time:-1;
    }
};
