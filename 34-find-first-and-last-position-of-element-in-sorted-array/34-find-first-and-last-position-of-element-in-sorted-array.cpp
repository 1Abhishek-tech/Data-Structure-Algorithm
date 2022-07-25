class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int i = 0 , j = nums.size() - 1;
      int l = -1 , r = -1;
      while(i <= j){
        int mid = i + (j - i)/2;
        if(nums[mid] == target) l = mid , j = mid - 1;
        else if (nums[mid] > target) j = mid - 1;
        else i = mid + 1;
      }
      i = 0 , j = nums.size() - 1;
        while(i <= j){
        int mid = i + (j - i)/2;
        if(nums[mid] == target) r = mid , i = mid + 1;
        else if (nums[mid] > target) j = mid - 1;
        else i = mid + 1;
      }
      if( l == -1 || r == -1) return {-1,-1};
      return {l,r};
    }
};