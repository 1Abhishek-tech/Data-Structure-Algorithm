class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      int n = magazine.size() , m = ransomNote.size();
      int mp[26] = {0};
      for(int i = 0 ; i < m ; i++){
        char ch = ransomNote[i];
        mp[ch - 'a']++;
      }
      for(int i = 0 ; i < n ; i++){
        char ch = magazine[i];
        if(mp[ch - 'a'] != 0) mp[ch - 'a']--;
      }
      bool flag = true;
      for(int i = 0 ; i < 26 ; i++)
        if(mp[i] != 0)  flag = false;
      
      return flag;
    }
};