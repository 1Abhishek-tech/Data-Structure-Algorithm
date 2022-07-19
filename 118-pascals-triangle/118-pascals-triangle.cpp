class Solution {
public:
  vector< vector<int> > tri;
    vector<vector<int>> generate(int numRows) {
      //bottom up iterative
      //   int n = numRows;
      // vector< vector<int> > tri(n);
      // for(int i = 0 ; i < n ; i++){
      //   tri[i] = vector<int> (i+1,1);
      //   for(int j = 1 ; j < i ; j++){
      //     tri[i][j] = tri[i-1][j] + tri[i-1][j-1];
      //   }
      // }
      // return tri;
      
      //top down recursive
      if(numRows){
        generate(numRows - 1);
         vector<int> row(numRows,1);
        tri.push_back(row);
        for(int i = 1 ; i < numRows-1 ; i++){
          tri[numRows-1][i] = tri[numRows-2][i] + tri[numRows-2][i-1];
        }
      }
      return tri;
    }
};