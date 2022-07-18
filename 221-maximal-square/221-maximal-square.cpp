class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size() , cols = matrix[0].size();
      // vector< vector<int> > dp(rows, vector<int> (cols,0));
      vector<int> pre(cols,0) , curr(cols,0);

      int largest = 0;
      for(int i = 0 ; i<rows ; i++){
        for(int j = 0 ; j<cols ; j++){
          if(!i || !j || matrix[i][j] == '0')
            // dp[i][j] = matrix[i][j] - '0';
            curr[j] = matrix[i][j] - '0';
          else{
            // dp[i][j] = min(min(dp[i][j-1] , dp[i-1][j]),dp[i-1][j-1]) + 1;
            curr[j]  = min(min(curr[j-1] , pre[j]),pre[j-1]) + 1;
          }
          // largest = max(largest,dp[i][j]);
          largest = max(largest,curr[j]);
        }
          fill(pre.begin(),pre.end(),0);
          swap(pre,curr);
      }
        return largest*largest;
      }
};