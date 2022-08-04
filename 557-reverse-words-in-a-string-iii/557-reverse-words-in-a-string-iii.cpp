class Solution {
public:
   void reverseString(string& s) {
      int n = s.length();
        for(int i = 0 ; i < n/2 ; i++){
          swap(s[i] , s[n-i-1]);
        }
    }
    string reverseWords(string s) {
      int i = 0 ,j ;
      for( j = 0 ; j < s.length() ; j++){
        if(s[j] == ' '){
          reverse(s.begin()+i , s.begin() + j);
          i = j+1;
        }
        
      }
      reverse(s.begin()+i,s.begin()+j);
      return s ;
      //   vector<string> word ;
      // string currword = "";
      // for(int i = 0 ; i < s.length() ; i++){
      //   if(s[i] == ' '){
      //     if(currword != " " && currword != "") word.push_back(currword);
      //     currword = "";
      //   }else
      //   currword+=s[i];
      // }
      // if(currword != " " && currword != "") word.push_back(currword);
      // for(int i = 0 ; i < word.size() ; i++){
      //   reverseString(word[i]);
      // }
      // string ans;
      // for(int i = 0 ; i < word.size() ; i++){
      //   ans+=word[i];
      //   if(i != word.size()-1 )
      //   ans+=" ";
      // }
      // return ans;
    }
};