class Solution {
public:
    vector<vector<int>> ans;
  
    void dfs(vector<vector<int>>& graph,vector<int>& vis,vector<int>& v,int s,int d){
      if(s == d){
        v.push_back(s);
        ans.push_back(v); v.pop_back();
        return;
      }
      v.push_back(s);
      vis[s] = 1;
      for(auto node : graph[s]){
        if(vis[node] == 0)
          dfs(graph,vis,v,node,d);
      }
      v.pop_back();
      vis[s] = 0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      vector<int> v;
      vector<int> vis(graph.size(),0);
      dfs(graph,vis,v,0,graph.size()-1);
      return ans;
    }
};