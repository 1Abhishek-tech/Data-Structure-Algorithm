class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n =matrix.size();
      for(int i=0;i<n/2;i++){
        for(int j=i;j<n-i-1;j++){
          int temp = matrix[i][j];
          matrix[i][j] = matrix[n-1-j][i];
          matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
          matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
          matrix[j][n-1-i] = temp;
          
          //anticlockwise
          //   int temp = matrix[i][j];
          // matrix[i][j] = matrix[j][n-1-i];
          // matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
          // matrix[n-1-i][n-1-j] = matrix[n-1-j][i];
          // matrix[j][n-1-i] = temp;
        }
      }
      //other ways
      //CW
       // Transpose the matrix
         // swap colums
          // Transpose the matrix
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < i; j++) {
    //         swap(matrix[i][j], matrix[j][i]);
    //     }
    // }
 
    // swap columns
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N/2; j++) {
    //         swap(matrix[i][j], matrix[i][N - j - 1]);
    //     }
    // }
      
      
      
      
       //ACW
       // Transpose the matrix
         // swap rows
          // Transpose the matrix
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < i; j++) {
//             swap(mat[i][j], mat[j][i]);
//         }
//     }
 
//     // swap rows
//     for (int i = 0; i < N/2; i++)
//     {
//         for (int j = 0; j < N; j++) {
//             swap(mat[i][j], mat[N - i - 1][j]);
//         }
//     }
    }
};