class Solution {
public:
  void dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 or j<0 or j>=grid[0].size() or i>=grid.size() or grid[i][j]==1)
                return;
        
        grid[i][j]=1;  
                
         dfs(grid,i-1,j);
         dfs(grid,i,j+1);
         dfs(grid,i+1,j);
         dfs(grid,i,j-1);
    }
    int closedIsland(vector<vector<int>>& grid) {
     
        int island=0,m=grid.size(),n=grid[0].size();
          
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
               if( (i==0 or j==0 or i==m-1 or j==n-1) and  grid[i][j]==0) 
                  dfs(grid,i,j);       //corner row aur col and grid[i][j]==0
        }   
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                {
                    island++;
                    dfs(grid,i,j);      
                }
            }  
        }   
        return island;
    }
};