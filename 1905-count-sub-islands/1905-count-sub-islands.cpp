class Solution {
public:

  void dfs(vector<vector<int>>& grid,int i,int j){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == 0)
      return ;
      grid[i][j] = 0 ;
    dfs(grid,i-1,j);
    dfs(grid,i,j+1);
    dfs(grid,i+1,j);
    dfs(grid,i,j-1);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(),m = grid1[0].size();
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(grid2[i][j] == 1 && grid1[i][j] == 0)
            dfs(grid2,i,j);
        }
      }
 
      int subIslands = 0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(grid2[i][j] == 1){
            dfs(grid2,i,j);
               subIslands++; 
          }
        }
      }
      return subIslands;
    }
};