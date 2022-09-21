class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
      vector<int> ans; int m = queries.size() , n = nums.size() ;
      int sum = 0;
      for(int i = 0 ; i < n ; i++){
        if(nums[i]%2 == 0)
          sum += nums[i];
      }
      for(int i = 0 ; i < m ; i++){
        int idx = queries[i][1] , val = queries[i][0] ;
        int curr = nums[idx];
        nums[idx] = nums[idx] + val;
        
        if(nums[idx]%2 == 0)
          sum = sum + nums[idx];
        if(curr%2 == 0) sum -= curr;
        ans.push_back(sum);
      }
      return ans;
    }
};