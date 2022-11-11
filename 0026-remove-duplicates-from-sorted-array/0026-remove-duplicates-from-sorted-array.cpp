class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1) return 1;
        
        int count = 1 , cur = nums[0];
        for(int i = 1 ; i < n ; i++){
            if(cur == nums[i]){
                nums[i] = -101;
            }
            else{
                count++;
                cur = nums[i];
            } 
        }
        
        int i = 1 , j = 1;
        while(i <= count && j < n){
            if(nums[j] != -101){
                nums[i] = nums[j];  
                i++;
            }
            j++;
        }
        
        return count;
    }
};