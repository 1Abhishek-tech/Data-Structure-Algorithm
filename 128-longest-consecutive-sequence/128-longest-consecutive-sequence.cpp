class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> s(nums.begin(),nums.end()); // faster way to insert in set
      
      int longestSeq = 0;
      for(int i=0;i<nums.size();i++){
        if(s.find(nums[i] - 1) != s.end())
          continue;
        //if previous element is not present then current element is the starting of sequence
        else{
          int count = 0;
          int current_element = nums[i];
          while(s.find(current_element) != s.end()){
            count ++;
            current_element++;
          }
          longestSeq = max(longestSeq,count);
        }
      }
      
      return longestSeq;
      
      
      
      // TLE Error
//         vector<long long int> sppos(10000001,-1);
//         vector<long long int> spneg(10000001,1);
//       for(int i=0;i<nums.size();i++){
//         if(nums[i]<0){
//           spneg[abs(nums[i])] = nums[i];
//         }
//         else{
//         sppos[nums[i]] = nums[i];
//         }
//       }
//       int len = 0,maxl = 0;
//       for(int i=spneg.size()-2;i>0;i--){
//         if(spneg[i]!= 1){
//           len++;
//           maxl = max(maxl,len);
//         }
//         else{
//           len = 0;
//         }
//       }
//       for(int i=0;i<sppos.size();i++){
  
        
//         if(sppos[i] != -1){
//           len++;
//           maxl = max(maxl,len);
//         }
//         else{
//           len = 0;
//         }
//       }
//       return maxl;
    }
};