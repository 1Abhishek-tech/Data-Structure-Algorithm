class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lesser , greater , equal ;
      
      for( auto x : nums){
        if(x < pivot) lesser.push_back(x);
        else if(x > pivot) greater.push_back(x);
        else equal.push_back(x);
      }
      lesser.insert(lesser.end(),equal.begin(),equal.end());
      lesser.insert(lesser.end(),greater.begin(),greater.end());
      return lesser;
    }
};