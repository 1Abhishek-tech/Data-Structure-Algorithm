class Solution {
public:
    int solve(vector<int>&v,int k){
        int maxi = INT_MIN;
       for(int i=0;i<v.size();i++){
           int sum = 0;
           for(int j = i;j<v.size();j++){
               sum+=v[j];
               if(sum<=k && sum>maxi) maxi = sum;
           }
       }
        return maxi;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int _k) {
      
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = INT_MIN;
        for(int i=0;i<row;i++){
            vector<int>v(col);
            for(int j=i;j<row;j++){
                for(int k=0;k<col;k++){
                    v[k] = v[k] + matrix[j][k];
                }
                 ans = max(ans,solve(v,_k));   
            }
        }
        return ans;
    }
};