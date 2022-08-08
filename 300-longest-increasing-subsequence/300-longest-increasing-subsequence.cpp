class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
      vector<int>dp(n+1,1);
      int sub = 1;
      for(int i = 0 ; i < n ; i++){
        int maxcurr = 0;
        for(int j = 0 ; j < i ; j++){
          
          if(nums[j] < nums[i] ){
            if(dp[j] > maxcurr) maxcurr = dp[j];
          }
          
        }
        dp[i] = maxcurr + 1;
        sub = max(sub,dp[i]);
      }
      return sub;
    }
};