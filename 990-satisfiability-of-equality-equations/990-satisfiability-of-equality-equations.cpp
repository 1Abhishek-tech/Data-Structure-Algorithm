class Solution {
public:
  // void dfs(vector<int>adj[],int src,int dis,bool &flag,vector<int> vis){
  //        if(src==dis){
  //            flag=true;
  //            return;
  //        }
  //        vis[src]=true;
  //      for(auto x:adj[src]){
  //          if(!vis[x]){
  //            dfs(adj,x,dis,flag,vis);
  //          }
  //      }
  // }
   int mem[26]; 
    int find(int x) {
        return x == mem[x] ? x : mem[x] = find(mem[x]);
    }
    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i <26; i++)
            mem[i] = i;
        for(auto s: equations) 
            if(s[1] == '=')
                mem[find(s[0]-'a')] = find(s[3]-'a');
        for(auto s: equations)
            if(s[1] == '!' and find(s[0]-'a') == find(s[3]-'a'))
                return false;
        return true;
        // int n=equations.size();
        // vector<int>adj[26];
        // for(int i=0;i<n;i++){
        //     if(equations[i][1]=='='){
        //       adj[equations[i][0]-'a'].push_back(equations[i][3]-'a');
        //       adj[equations[i][3]-'a'].push_back(equations[i][0]-'a');
        //     }
        // }
        //   for(int i=0;i<n;i++){
        //     if(equations[i][1]=='!'){
        //         bool flag=false;
        //         vector<int> vis(26);
        //         dfs(adj,equations[i][0]-'a', equations[i][3]-'a',flag,vis);
        //         if(flag){
        //           return false;
        //       }
        //     }
        // }
        // return true;
    }
};