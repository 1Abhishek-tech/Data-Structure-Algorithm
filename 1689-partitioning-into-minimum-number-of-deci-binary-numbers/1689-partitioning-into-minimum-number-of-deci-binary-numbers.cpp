class Solution {
public:
    int minPartitions(string n) {
        int min = INT_MIN;
      for(int i=0;i<n.size();i++){
        int temp = n[i] - '0';
        if(temp>min){
          min = temp;
        }
        
      }
      return min;
    }
};