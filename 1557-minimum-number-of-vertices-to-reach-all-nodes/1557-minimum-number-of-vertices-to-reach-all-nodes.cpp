class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> degree(n,false); 
        vector<int> result;
        for(int i=0;i<edges.size();i++) {
            degree[edges[i][1]] = true;
        } 
        for(int i=0;i<n;i++) 
            if(!degree[i])
                result.push_back(i);
        return result;
    }
};