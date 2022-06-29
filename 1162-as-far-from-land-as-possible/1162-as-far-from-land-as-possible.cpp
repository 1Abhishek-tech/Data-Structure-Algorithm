class Solution
{
    public:
        int dx[4] = { 0,0,-1,1};
    int dy[4] = { -1,1,0,0};
    int maxDistance(vector<vector < int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector < int>> dist(n, vector<int> (m, INT_MAX));
        queue<pair<int, int>> q;

       	// include those nodes which are already zero and mark their distance as 0.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({ i,
                        j });
                    dist[i][j] = 0;
                }
            }
        }
        int ans = 0;
       	// visit every cell and update their distance
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

           	// traverse all four direction
            for (int i = 0; i < 4; i++)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
               	// cases where we need to go for next cells
                if (xx >= 0 && xx < n && yy >= 0 && yy < m && dist[xx][yy] == INT_MAX)
                {
                    q.push({ xx,
                        yy });
                    dist[xx][yy] = dist[x][y] + 1;
                   	// update the answer
                    ans = max(ans, dist[xx][yy]);
                }
            }
        }

       	// cases where we only have land(ans = INT_MAX) or only have water(ans = 0)
        if (ans == INT_MAX or ans == 0) return -1;
        return ans;
    }
};