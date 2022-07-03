class Solution {
public:
    void dfs( vector<vector<int>>& edges,int i,vector<bool>& visited){
        visited[i]=true;
        for(auto itr:edges[i])
            if(!visited[itr])
                dfs(edges,itr,visited);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> edges(n);
        unordered_map<int,int> mp; //For checking which no is present in edges and it is also helpful in calcation of no of cycle present 
        for(auto itr:connections)
        {
            mp[itr[0]]=1,mp[itr[1]]=1;
            edges[itr[0]].push_back(itr[1]);
            edges[itr[1]].push_back(itr[0]);
        }
        int cycle=connections.size()-mp.size() + 1;
        int count=n-mp.size();
        if(count>cycle)
            return -1;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
            if(!visited[i]&&mp.find(i)!=mp.end())
            {
                count++;
                dfs(edges,i,visited);
            }
        if(count-1<=cycle) 
            return count-1;
        return -1;
    }
};