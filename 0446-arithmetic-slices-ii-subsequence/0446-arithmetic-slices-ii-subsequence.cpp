class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<long,long> mp[n];
        
        
        int res = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                long diff = (long)nums[i] - nums[j];
                
                int count_at_j = 0;
                if(mp[j].find(diff) != mp[j].end()){
                    count_at_j = mp[j][diff];
                }
                else mp[j][diff] = 0;
                
                mp[i][diff] += count_at_j+1;
                res += count_at_j;
                
            }
        }
        
        return res;
    }
};