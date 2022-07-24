class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowLength = matrix.size();
        //Checking if there are no rows and hence returning false 
        if(rowLength == 0)
            return false;
        int colLength = matrix[0].size();
        
        int i = 0, j = colLength - 1;   //Starting from the top-right of the matrix
        //Moving left if the target is less than the value since column values below would be greater
        //Moving down if the target is greater than the value because all the values on the left would be smaller
        while( i < rowLength && j >= 0)
        {
            if(matrix[i][j] == target){
                return true;
            }
            else if(matrix[i][j] > target){     //If the current value is greater, then it means the values below this i.e. inside this column would be greater, therefore moving to the left
                j--;
            }
            else{   //Moving down, because all the values would be smaller on the left
                i++;
            }
        }
        return false;
    }
};