class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
      vector< vector<int> > tri(n);
      for(int i = 0 ; i < n ; i++){
        tri[i] = vector<int> (i+1,1);
        for(int j = 1 ; j < i ; j++){
          tri[i][j] = tri[i-1][j] + tri[i-1][j-1];
        }
      }
      return tri;
    }
};