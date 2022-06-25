class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
      // conditions to check if pos is -1 or changed from -1 once, then check pos[i+1]>=pos[i-1] or           pos[i+2]>=pos[i] and check for edge cases
      int pos = -1;
      for(int i=0;i<nums.size()-1;i++){
        if(nums[i]>nums[i+1]){
          if(pos != -1){
            return false;
          }
          pos = i;
        }
        
      }
      return pos == -1 || pos == 0 || pos == nums.size()-2 || nums[pos+2]>=nums[pos] || nums[pos+1]>=nums[pos-1] ;
    }
};