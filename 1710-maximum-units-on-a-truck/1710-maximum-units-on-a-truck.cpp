class Solution {
public:
  static bool comp(vector<int> &a,vector<int> &b ){
    return a[1] > b[1];
  }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
      int res = 0,i=0;
         while(i<boxTypes.size() && truckSize>0){
        int curr = boxTypes[i][0]*boxTypes[i][1];
        if(truckSize>=boxTypes[i][0]){
          truckSize-=boxTypes[i][0];
          res+=curr;
        }
        else{
          int canTakeBox = truckSize;
          truckSize-=canTakeBox;
          res+= canTakeBox*boxTypes[i][1];
          break;
        }
           i++;
      }
      return res;
    }
};