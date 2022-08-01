class Solution {
public:
    int uniquePaths(int m, int n) {
        
      int dp[m][n];
      
      for(int i=0;i<m;i++){
        dp[i][0] = 1;
      }
      for(int i=0;i<n;i++){
        dp[0][i] = 1;
      }
      for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
          dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
      }
      return dp[m-1][n-1];
    }
};
// https://leetcode.com/problems/unique-paths/discuss/2109285/C%2B%2B-Solution-or-Recursion-or-DP-or-DP(optimized-Space)-or-Time-complexity
        //aproach is to use dp to divide the problem into subproblems
        //for reaching to bottom -right we have 3 cases like we can either go through corner ways like first column last row or first row last column  or middle columns & middle rows
        
        // int dp[m][n];
        // for(int i=0;i<m;i++){
        //     dp[i][0]=1;
        // }
        // for(int j=0;j<n;j++){
        //     dp[0][j]=1;
        // }
        // for(int i=1;i<m;i++){
        //     for(int j=1;j<n;j++){
        //         dp[i][j]=dp[i-1][j]+dp[i][j-1];
        //     }
        // }
        // return dp[m-1][n-1];