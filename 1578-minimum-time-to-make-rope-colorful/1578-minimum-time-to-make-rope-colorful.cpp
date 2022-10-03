class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
      char c1 = colors[0] , c2; int t1 = neededTime[0] , t2;
      for(int i = 1 ; i < colors.size() ; i++){
          c2 = colors[i]; t2 = neededTime[i];
          if(c1 == c2){
            if(t1 > t2){
              res += t2; 
            }
            else{
              res += t1;
              c1 = c2; t1 = t2;
            }
            
          }else{
            c1 = c2; t1 = t2;
          }
      }
      return res;
    }
};