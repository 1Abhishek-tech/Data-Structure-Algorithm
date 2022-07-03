class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int> > graph(n);
        int par[n]; bool vis[n];
        for(int i=0;i<n;i++) {
            par[i]=-1;                             // par = parent node
            vis[i]=false;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(isConnected[i][j] == 1) {
                    graph[i].push_back(j);      
                    graph[j].push_back(i);
                    par[j] = i;
                    if(par[i]!=-1)
                        graph[j].push_back(par[i]); // for indirectly connected cities
                }
            }
        }
        queue<int> q;
        int ans=0;
        for(int i=0;i<n;i++) {
            if(vis[i]==false) {
                ans++;
                q.push(i);
                while(!q.empty()) {
                    int h = q.front();
                    q.pop();
                    vis[h]=true;
                    for(auto x: graph[h]) {
                        if(vis[x]==false)
                            q.push(x);
                    }
                }
            }
        }
        return ans;
    }
};