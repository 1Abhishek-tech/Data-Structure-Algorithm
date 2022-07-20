class Solution {
public:
  bool isSubsequence(string s , string s1){
    int ptr1 = 0 , ptr2 = 0;
    int n = s.length() , n1 = s1.length();
    while(ptr1 < n && ptr2 < n1){
      if(s[ptr1] == s1[ptr2]) {
        ptr1++ , ptr2++;
      }
      else
        ptr1++;
      if(ptr2 == n1) return true;
    }  
    return false;
  }
    int numMatchingSubseq(string s, vector<string>& words) {
      int count = 0;
      unordered_map<string,int> map;
      for(int k = 0 ; k < words.size() ; k++){
        map[words[k]]++;
      }
        for(auto word : map){
          if(isSubsequence(s,word.first) )
            count+=word.second;
        }
      return count;
    }
};