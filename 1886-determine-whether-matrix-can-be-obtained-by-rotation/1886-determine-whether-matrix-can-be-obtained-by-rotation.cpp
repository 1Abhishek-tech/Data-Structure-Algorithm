class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size(); bool flag , ans ;
      //1st rot
      flag = true;
      for(int i = 0 ; i < n/2 ; i++){
        for(int j = i ; j < n-i-1 ; j++){
          int temp = mat[i][j];
          mat[i][j] = mat[n-j-1][i];
          mat[n-j-1][i] = mat[n-i-1][n-j-1];
          mat[n-i-1][n-j-1] = mat[j][n-i-1];
          mat[j][n-i-1] = temp;
        }
      }
      for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
          if(mat[i][j] != target[i][j]) flag = false;
        }
      }
      if(flag == true) return true;
      
      
      //2nd rot
      flag = true;
      for(int i = 0 ; i < n/2 ; i++){
        for(int j = i ; j < n-i-1 ; j++){
          int temp = mat[i][j];
          mat[i][j] = mat[n-j-1][i];
          mat[n-j-1][i] = mat[n-i-1][n-j-1];
          mat[n-i-1][n-j-1] = mat[j][n-i-1];
          mat[j][n-i-1] = temp;
        }
      }
      for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
          if(mat[i][j] != target[i][j]) flag = false;
        }
      }
      if(flag == true) return true;
      
      //3rd rot
      flag = true;
      for(int i = 0 ; i < n/2 ; i++){
        for(int j = i ; j < n-i-1 ; j++){
          int temp = mat[i][j];
          mat[i][j] = mat[n-j-1][i];
          mat[n-j-1][i] = mat[n-i-1][n-j-1];
          mat[n-i-1][n-j-1] = mat[j][n-i-1];
          mat[j][n-i-1] = temp;
        }
      }
      for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
          if(mat[i][j] != target[i][j]) flag = false;
        }
      }
      if(flag == true) return true;    
      
      //4th rot
      flag = true;
      for(int i = 0 ; i < n/2 ; i++){
        for(int j = i ; j < n-i-1 ; j++){
          int temp = mat[i][j];
          mat[i][j] = mat[n-j-1][i];
          mat[n-j-1][i] = mat[n-i-1][n-j-1];
          mat[n-i-1][n-j-1] = mat[j][n-i-1];
          mat[j][n-i-1] = temp;
        }
      }
      for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
          if(mat[i][j] != target[i][j]) flag = false;
        }
      }
      if(flag == true) return true;  
      
      return false;
    }
};