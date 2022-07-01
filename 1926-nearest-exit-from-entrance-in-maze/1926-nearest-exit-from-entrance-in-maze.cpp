class Solution
{
    public:
    //up down left right
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) {
        int ans = 0;
        queue<pair<int,int>>qu;
        qu.push({entrance[0], entrance[1]});
        
        while(!qu.empty()){
            int size = qu.size();
            
            while(size--){
                int i = qu.front().first;
                int j = qu.front().second;
                qu.pop();
                
                if((i == 0 or j == 0 or i==grid.size()-1 or j == grid[0].size()-1) and (i!=entrance[0] or j!=entrance[1])){
                    return ans;
                }
                
                for(int d = 0; d<4; d++){
                    int currx = i+dx[d];
                    int curry = j+dy[d];

                    if(currx>=0 and currx<grid.size() and curry>=0 and curry<grid[0].size() and grid[currx][curry]=='.'){
                        grid[currx][curry] = '+';       
                        qu.push({currx, curry});
                    }
                }
            }
            
            ans++;
        }
        
        return -1;
    }
};