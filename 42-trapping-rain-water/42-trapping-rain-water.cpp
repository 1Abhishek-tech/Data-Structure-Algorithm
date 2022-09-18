class Solution {
public:
    int trap(vector<int>& height) {
      int leftend = 0 , rightend = height.size() - 1;
      int maxleft = height[leftend] , maxright = height[rightend];
      int ans = 0;
      
      while(leftend < rightend){
        
        maxleft = max(maxleft , height[leftend]);
        maxright = max(maxright , height[rightend]);
        
        ans += min(maxleft , maxright) - min(height[leftend] , height[rightend]);
        
        if(height[leftend] < height[rightend]) leftend++;
        else rightend--;
      }
      
      return ans;
    }
};