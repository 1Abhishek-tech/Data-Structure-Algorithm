class Solution {
public:
    bool isSubsequence(string s, string t) {
      if(s.length() == 0) return true;
    int ptr1 = 0 , ptr2 = 0;
    int n = t.length() , n1 = s.length();
    while(ptr1 < n && ptr2 < n1){
      if(t[ptr1] == s[ptr2]) {
        ptr1++ , ptr2++;
      }
      else
        ptr1++;
      if(ptr2 == n1) return true;
    }  
    return false;
    }
};