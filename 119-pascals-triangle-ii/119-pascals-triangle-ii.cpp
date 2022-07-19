class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex + 1;
      vector< vector<int> > tri(n);
      for(int i = 0 ; i < n ; i++){
        tri[i].resize(i+1,1);
        for(int j = 1 ; j < i ; j++){
          tri[i][j] = tri[i-1][j] + tri[i-1][j-1];
        }
      }
      return tri[n-1];
    }
};