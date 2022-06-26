class Solution {
    public:
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int m, n;
void bfs(vector<vector<int>>& visited,vector<vector<char>>& grid, queue<pair<int,int>>& q){
        int curr_x, curr_y;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                curr_x = x + dx[k];
                curr_y = y + dy[k];
                if(curr_x<m&& curr_x>=0 && curr_y<n && curr_y>=0){
                    if(grid[curr_x][curr_y]=='1' && visited[curr_x][curr_y]==0){
                        q.push({curr_x, curr_y});
                        visited[curr_x][curr_y]=1;
                    }
            
                }
        
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
                        int count{0};
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    q.push({i,j});
                    visited[i][j] = 1;
                    count++;
                    bfs(visited, grid, q);
                }
            }
        }
        return count;

    }
};