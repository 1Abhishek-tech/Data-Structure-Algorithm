class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int zeroes = 0 , index = 0;
      for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i] == 0) zeroes++;
        else {
          nums[index] = nums[i];
          index++;
        }
      }
      for(int i = 0 ; i < zeroes ; i++) nums[index + i] = 0;
    }
};