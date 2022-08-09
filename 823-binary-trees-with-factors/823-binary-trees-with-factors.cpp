class Solution {
public:
  int mod = 1000000007;
    int numFactoredBinaryTrees(vector<int>& arr) {
      sort(arr.begin(),arr.end());
      
      map<long long int , long long int > count;
      for(auto x : arr) count[x] = 1;
      
      for(int i = 1 ; i < arr.size() ; i++){
        for(int j = 0 ; j <= i-1 ; j++){
          if(arr[i]%arr[j] == 0){
            int rc = arr[i]/arr[j];
            if(count[rc]){
              count[arr[i]] = (count[arr[i]] + (count[arr[j]] * count[rc]))%mod;
            }
          }
        } 
      }
      
      long long int sum = 0;
      for(auto [x,y] : count) sum=(sum+y)%mod;
      
      return sum;
    }
};