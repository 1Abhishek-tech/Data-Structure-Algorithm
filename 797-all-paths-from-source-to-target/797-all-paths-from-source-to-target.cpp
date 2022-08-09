class Solution {
public:
    vector<vector<int>> paths;
  
  void dfs(vector<vector<int>>& graph,vector<int>& vis,vector<int>&path,int s,int d){
      if(s == d){
        path.push_back(s);
        paths.push_back(path);
        path.pop_back();
        return ;
      }
      path.push_back(s);
      vis[s] = 1;
      for(auto node : graph[s]){
        if(vis[node] == 0){
           dfs(graph,vis,path,node,d);
        }
      }
     vis[s] = 0;
     path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      vector<int> path;
      vector<int> vis(graph.size(),0);
      dfs(graph,vis,path,0,graph.size()-1);
      return paths;
    }
};