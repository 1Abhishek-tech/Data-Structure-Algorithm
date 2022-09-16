class Solution {
public:


    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        
        vector<int> dp(m+1, 0), temp(m+1,0);

        for(int i=m-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                int x = multipliers[i]*nums[j] + dp[j+1];
                int y = multipliers[i]*nums[n-1 - (i-j)] + dp[j];
                
                temp[j] = max(x,y);
            }
            dp = temp;
        }
        
        return dp[0];
    }
};