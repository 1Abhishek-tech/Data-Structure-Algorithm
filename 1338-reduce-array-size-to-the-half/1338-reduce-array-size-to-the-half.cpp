class Solution {
public:
    int minSetSize(vector<int>& arr) {
      unordered_map<int,int> mp;
      for(auto x : arr) mp[x]++;
      vector<int> freq;
      for(auto [_ , fre] : mp) freq.push_back(fre);
      
      sort(freq.begin() , freq.end());
      
      int ans = 0, removed = 0 , half = arr.size()/2 , i = freq.size() - 1;
      
      while(removed < half){
        ans++;
        removed += freq[i--];
      }
      return ans;

    }
};