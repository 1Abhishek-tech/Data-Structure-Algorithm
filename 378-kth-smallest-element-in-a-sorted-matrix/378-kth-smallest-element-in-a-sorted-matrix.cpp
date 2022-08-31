class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      int n = matrix.size();
//       priority_queue<int , vector<int> , greater<int> > pq_min; 
//         for(int i = 0 ; i < n ; i++)
//           for(int j = 0 ; j < n ; j++){
//             pq_min.push(matrix[i][j]);
//           }
      
//       for(int i = 1 ; i < k ; i++){
//         pq_min.pop();
//       }
//       return pq_min.top();
      int ans = 0;
        int l = matrix[0][0] , r = matrix[n-1][n-1];
      while(l <= r){
        int mid = l + (r - l)/2 ;
        int count = 0;
        for(int i = 0 ; i < n ; i++)
          count += upper_bound(matrix[i].begin() , matrix[i].end() , mid ) - matrix[i].begin();
        
        if( count >= k ){
          ans = mid ;
          r = mid - 1;
        }
        else 
          l = mid + 1;
      }
      return ans;
    }
};