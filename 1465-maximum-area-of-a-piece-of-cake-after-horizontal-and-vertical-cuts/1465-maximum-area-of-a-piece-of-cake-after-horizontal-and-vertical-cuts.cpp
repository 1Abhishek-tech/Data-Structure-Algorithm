#define rep(i,a,b) for(int i=a;i<b;i++)
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
      sort(horizontalCuts.begin(),horizontalCuts.end());
      sort(verticalCuts.begin(),verticalCuts.end());
      long long diff = 0;
      long long int maxh = 0,maxv = 0;
      bool flagh = false,flagv = false;
      if(horizontalCuts.size() == 1){
        flagh = true;
        diff = horizontalCuts[0];
        long long int hh = h-horizontalCuts[0];
        maxh = max(diff,hh);
      }
      diff = 0;
      if(verticalCuts.size() == 1){
        flagv = true;
        diff = verticalCuts[0];
        long long int vv = w-verticalCuts[0];
        maxv = max(diff,vv);
      }
      diff = 0;
      if(!flagh){
      rep(i,1,horizontalCuts.size()){
        diff = horizontalCuts[i] - horizontalCuts[i-1];
        maxh = max(maxh,diff);
      }
        long long int hh = h - horizontalCuts[horizontalCuts.size()-1];
        maxh = max(maxh,hh);
        diff = horizontalCuts[0];
        maxh = max(maxh,diff);
      }
      diff = 0;
      if(!flagv){
      rep(i,1,verticalCuts.size()){
        diff = verticalCuts[i] - verticalCuts[i-1];
        maxv = max(maxv,diff);
      }
        long long int vv = w - verticalCuts[verticalCuts.size()-1];
        maxv = max(maxv,vv);
        diff = verticalCuts[0];
        maxv = max(maxv,diff);
      }  
      return (maxh*maxv)%1000000007;
    }
};