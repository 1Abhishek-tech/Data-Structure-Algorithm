class Solution {
public:
  int helper(string &text1, string &text2, int n , int m , int dp[][1001]){
    if ( n == 0 || m == 0 ) return 0;
    if(dp[n][m] != -1 ) return dp[n][m];
    if(text1[n-1] == text2[m-1]) return dp[n][m] = 1 + helper(text1,text2,n-1,m-1,dp);
    
    int op1 = helper(text1,text2,n-1,m,dp);
    int op2 = helper(text1,text2,n,m-1,dp);
    return dp[n][m] = max(op1,op2);
  }
    int longestCommonSubsequence(string text1, string text2) {
      int n = text1.size(), m = text2.size();
      int dp[1001][1001] ;
       // for(int i=0;i<1001;i++){
       //      for(int j=0;j<1001;j++){
       //          memo[i][j]=-1;
       //      }
       //  }
      memset( dp, -1, sizeof(dp) );
      return helper(text1,text2,n,m,dp);
    }
};