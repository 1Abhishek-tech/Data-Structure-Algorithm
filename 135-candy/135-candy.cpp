#define rep(i,a,b) for(int i=a;i<b;i++) 
class Solution {
public:
    int candy(vector<int>& ratings) {
        int candy = 0,n = ratings.size();
        vector<int> candiesL2R(n,1);
        vector<int> candiesR2L(n,1);

       // it take care about student get more candies than its left neighbor
        rep(i,1,n){
          if(ratings[i-1]<ratings[i]){
            candiesL2R[i] = candiesL2R[i-1] + 1;
          }   
        }
       // it take care about student get more candies than its right neighbor
        for(int i=n-2;i>=0;i--){
          if(ratings[i+1]<ratings[i]){
            candiesR2L[i] = candiesR2L[i+1] + 1;
          }   
        }
        // here we take the maximum value which satisfy both the left and the right neighbor condition 
      rep(i,0,n){
        candy += max(candiesL2R[i],candiesR2L[i]); 
      }
      return candy;
      
    }
};