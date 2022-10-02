class Solution {
public:
     /*Recursive
    int fun(int n,int k,int target)
    {
        //base case
        if(target<0)
            return 0;
        if(n==0 && target!=0)
            return 0;
        if(target==0 && n!=0)
            return 0;
        if(target==0 && n==0)
            return 1;

        int ans=0;
        for(int i=1;i<=k;i++)
        {
            ans+=fun(n-1,k,target-i);
        }
        int mod=1000000007;
        return ans%mod; 
    }
    int numRollsToTarget(int n, int k, int target) {
        return fun(n,k,target);
    }*/


    int fun(int n,int k,int target,vector<vector<int>>&dp)
    {
        //base case
        if(target<0)
            return 0;
        if(n==0 && target!=0)
            return 0;
        if(target==0 && n!=0)
            return 0;
        if(target==0 && n==0)
            return 1;
        if(dp[n][target]!=-1)
            return dp[n][target];
        long long ans=0;
        for(int i=1;i<=k;i++)
        {
            ans+=fun(n-1,k,target-i,dp);
        }
        int mod=1000000007;
        return dp[n][target]=ans%mod; 
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return fun(n,k,target,dp);
    }
};