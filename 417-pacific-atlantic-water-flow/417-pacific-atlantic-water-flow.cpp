class Solution {
public:
  // https://leetcode.com/problems/pacific-atlantic-water-flow/discuss/2184918/Simple-C%2B%2B-solution-using-only-DFS-%3A-Pacific-Atlantic-Water-Flow
  // https://leetcode.com/problems/as-far-from-land-as-possible/discuss/2184191/C%2B%2B-oror-BFS-oror-Easy-oror-Commented
    bool vis[200][200]; //visited array
   
    void reset(void)// Function to reset our visited array
    {
        for(int i=0;i<200;i++)
        {
            for(int j=0;j<200;j++)
            {
                vis[i][j]=0;
            }
        }
    }
    
    //function to check that is cell (r,c) is valid?
    bool isvalid(int r,int c,int n,int m)
    {
        if(r<0||r>=n ||c<0||c>=m) return 0;
        return 1;
    }
    
    //moves that water can take in matrix. 
    vector<pair<int,int>> moves={{0,1},{1,0},{-1,0},{0,-1}};
    
    //Our dfs function
    void dfs(int r,int c,int par,vector<vector<int>>& h,vector<vector<int>>& ocean)
    {
        //par -> it is the height of parent of current cell
        /* If water can flow from current cell to the parent cell it means
        from current cell water can flow to ocean */
        
        int n=h.size(),m=h[0].size();
        
        //if not valid position then return
        if(isvalid(r,c,n,m)==0) return;
        //if cell is already visited then return 
        if(vis[r][c]==1) return;
        
        //if water can't flow from current cell to its parent cell then return
        if(par>h[r][c]) return;
        
        if(par<=h[r][c])
        {
            /* we are here means water can flow from this cell to its parent cell means
            from this cell water can flow to target ocean */
            ocean[r][c]=1;
        }
        //Now this cell is visited so mark it visited
        vis[r][c]=1;
        
        /* Now we apply dfs to all connected cells from current cell 
        (by taking current cell as parent) */
        for(auto move:moves)
        {
            dfs(r+move.first,c+move.second,h[r][c],h,ocean);
        }        
    }

    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        
        /* We create two matrix with same dimension as heights matrix
        these matrix stores that can the cell (i,j) water go to respective ocean */
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        
        /* As all the cell directly in contact with the ocean their water can go in
        the connected ocean. So for that cells we use parent height as
        height of ocean(actually depth) .We use very small -ve value as height of ocean */
        int oceanheight=INT_MIN;
        
        /* All top cells and leftmost cells are connected to pacific ocean.*/
        /*
        So we run Dfs for every unvisited node of Top cells and leftmost cells 
        for pacific ocean
        */
        
        //for all top elements  (for top elements row=0)
        for(int j=0;j<m;j++)
        {
            if(vis[0][j]==0) //if not already visited
            {
                dfs(0,j,oceanheight,heights,pacific);
            }
        }
        //for all left most cells (for left most cells col=0)
        for(int i=0;i<n;i++)
        {
             if(vis[i][0]==0) //if not visited already
             {
                dfs(i,0,oceanheight,heights,pacific);
             }
        }
        
        /* Here we have to reset our visited array Because we have to reuse it for our
        next ocean dfs */
        reset();
        
        /* All Bottom cells and rightmost cells are connected to Atlantic ocean.*/
        // running atlanticdfs
        
         /*
        So we run Dfs for every unvisited node of Top cells and leftmost cells 
        for pacific ocean
        */
        
        //for all Bottom cells  (for Bottom cells row=n-1)
        for(int j=0;j<m;j++)
        {
             if(vis[n-1][j]==0) //if not already visited
             {
                dfs(n-1,j,oceanheight,heights,atlantic);
             }
        }
        //for all right most cells (for rigthmost cells dolumn= m-1)
        for(int i=0;i<n;i++)
        {
            if(vis[i][m-1]==0) //if not already visited
            {
                dfs(i,m-1,oceanheight,heights,atlantic);
            }
        }
        
        //in ans vector we store our answer
        vector<vector<int>> ans;
        
        /* Now counting the cell for which water can flow in both 
         pacific and atlantic oceans */
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //if water can flow from current cell to pacific then pacific[i][j]=1 
                //if water can flow from current cell to Atlantic then atlantic[i][j]=1 
                /* We have to find cell for which water can flow in both oceans. */
                if(pacific[i][j]==1 && atlantic[i][j]==1)
                    ans.push_back({i,j});
            }
        }
        return ans;  
    }
};