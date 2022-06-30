class Solution {
public:
  bool isValid(pair<int,int> neighbor,int n,int m){
    if(neighbor.first<0 || neighbor.first>=n || neighbor.second<0 || neighbor.second>=m)
      return false;
    return true;
  }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
      int m = mat[0].size();
      vector<vector<int>> dis(n,vector<int>( m,-1) );
      queue<pair<int,int>> q;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(mat[i][j] == 0){
            dis[i][j] = 0;
            q.push({i,j});
          }
        }
      }
      int dx[] = {-1,0,1,0};
      int dy[] = {0,1,0,-1};
      while(!q.empty()){
        pair<int,int> node = q.front();
        q.pop();
        for(int i=0;i<4;i++){
          pair<int,int> neighbor = {node.first + dx[i],node.second + dy[i]};
          if(isValid(neighbor,n,m) && dis[neighbor.first][neighbor.second] == -1){
            dis[neighbor.first][neighbor.second] = dis[node.first][node.second] + 1;
            q.push({neighbor.first,neighbor.second});
          }
        }
      }
      return dis;
    }
};