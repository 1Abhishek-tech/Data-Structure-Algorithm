class Solution {
public:
    int firstUniqChar(string s) {
//         unordered_map<char,pair<int,int>> map;
      
//       for(int i = 0 ; i < s.length() ; i++){
//         map[s[i]].first++; map[s[i]].second = i ;
//       }
//       int idx = -1;
//       for(int i = 0 ; i < s.length() ; i++){
//         if(map[s[i]].first == 1){ idx = map[s[i]].second; break; }
//       }
//       return idx;
      pair<int,int> map[26];
      for(int i = 0 ; i < s.length() ; i++){
        int pos = s[i] - 'a';
        map[pos].first++; map[pos].second = i;
      }
      int idx = INT_MAX;
      for(int i = 0 ; i < 26 ; i++){
        if(map[i].first == 1){
          idx = min(idx,map[i].second);
        }
      }
      return idx == INT_MAX ? -1 : idx;
    }
};