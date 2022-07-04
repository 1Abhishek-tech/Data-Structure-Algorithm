class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
                vector<int> vis(graph.size(),0);
        vector<int> rec(graph.size(),0);
        vector<int> res;
        for(int i=0;i<graph.size();i++)
        {
            if(cycle(graph,vis,rec,i)==0)
                res.push_back(i);
        }
        return res;  
    }
      bool cycle(vector<vector<int>>& adj,vector<int>& vis,vector<int>& rec,int i)
    {
        vis[i]=1;
        rec[i]=1;
        for(auto x:adj[i])
        {
            if(rec[x])
                return true;
            else if(vis[x]==0 && cycle(adj,vis,rec,x))
                return true;
        }
        return rec[i]=0;
    }
};