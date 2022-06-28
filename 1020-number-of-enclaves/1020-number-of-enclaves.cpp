class Solution {
public:
  int cells = 0;
  void dfs(vector<vector<int>> &grid,int i,int j){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == 0)
      return;
    grid[i][j] = 0;
    cells++;
    
    dfs(grid,i-1,j);
    dfs(grid,i,j+1);
    dfs(grid,i+1,j);
    dfs(grid,i,j-1);
  }
    int numEnclaves(vector<vector<int>>& grid) {
    int m=grid.size(),n=grid[0].size();
          
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
               if( (i==0 or j==0 or i==m-1 or j==n-1) and  grid[i][j]==1) 
                  dfs(grid,i,j);       //corner row aur col and grid[i][j]==0
        }   
        cells = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {         
                    dfs(grid,i,j);    
                }
            }  
        }   
        return cells;
    }
};