class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      int n = matrix.size();
      priority_queue<int , vector<int> , greater<int> > pq_min; 
        for(int i = 0 ; i < n ; i++)
          for(int j = 0 ; j < n ; j++){
            pq_min.push(matrix[i][j]);
          }
      
      for(int i = 1 ; i < k ; i++){
        pq_min.pop();
      }
      return pq_min.top();
      

    }
};