class Solution {
public:
  void dfs(vector<vector<int>>& rooms,vector<int>& vis,int src ){
    if(vis[src] == 1)
      return ;
    vis[src] = 1;
    for(auto node : rooms[src]){
      if(vis[node] == 0)
        dfs(rooms,vis,node);
    }
  }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size(),0);
      dfs(rooms,vis,0);
      for(int i=0;i<rooms.size();i++){
        int m = rooms[i].size();
        for(int j=0;j<m;j++){
          if(vis[rooms[i][j]] == 0)
            return false;
        }
      }
      return true;
    }
};