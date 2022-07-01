class Solution {
public:
   void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited, int n, queue<pair<int, int>> &q){
        if(i<0 || j<0 || i>=n || j>=n || visited[i][j] || grid[i][j]==0) return;
        
        visited[i][j] = true;
        q.push({i,j});
        int dir[]={0,1,0,-1,0};
        for(int x=0; x<4; x++){
            dfs(i+dir[x], j+dir[x+1], grid, visited, n, q);
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool flag = false;
        if(!n) return 0;
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        for(int i=0; i<n && !flag; i++){
            for(int j=0; j<n && !flag; j++){
                if(grid[i][j] == 1){
                    dfs(i,j,grid,visited, n, q);
                    flag=true;
                }
            }
        }
        
        int level=0;
        
        while(!q.empty()){
            int sze = q.size();
            while(sze--){
                auto top = q.front();
                int i = top.first;
                int j = top.second;
                q.pop();
                
                int dir[]={0,1,0,-1,0};
                for(int x=0; x<4; x++){
                    int nrow = i+dir[x];
                    int ncol = j+dir[x+1];
                    
                    if(nrow<0 || ncol<0 || nrow>=n || ncol>=n || visited[nrow][ncol]) continue;
                    if(grid[nrow][ncol] == 1) return level;
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
            level++;
        }
        return 0;
    }
};