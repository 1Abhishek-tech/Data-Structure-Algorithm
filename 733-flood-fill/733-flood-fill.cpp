class Solution {
public:
  int sColor = 0;
  void dfs(vector<vector<int>>& image, int sr, int sc, int newColor){
    if( sColor == image[sr][sc]){
              image[sr][sc] = newColor;
          for(int i=0;i<4;i++){
            if(i == 0 && sr-1>=0) dfs(image,sr-1,sc,newColor);
             if(i == 1 && sc+1<image[0].size()) dfs(image,sr,sc+1,newColor);
               if(i == 2 && sr+1<image.size()) dfs(image,sr+1,sc,newColor);
                 if(i == 3 && sc-1>=0) dfs(image,sr,sc-1,newColor);
          }
    }
  }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
      sColor = image[sr][sc];
        if(sColor != newColor){
            dfs(image,sr,sc,newColor);
        }
      return image;
    }
};