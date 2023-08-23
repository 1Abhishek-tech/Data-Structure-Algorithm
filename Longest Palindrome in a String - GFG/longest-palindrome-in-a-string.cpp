//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  // expand around center
  string checkPalindrome(string & s, int left, int right){
      while(left >= 0 && right < s.size() && s[left] == s[right]){
          left--;
          right++;
      }
      left++;
      right--;
      return s.substr(left, right - left + 1);
  }
    string longestPalin (string S) {
        // code here
        string longestPalindrome = "";
        
        for(int i = 0 ; i < S.size() ; i++){
            
            string str1 = checkPalindrome(S, i , i);
            if(str1.size() > longestPalindrome.size()) longestPalindrome = str1;
            
            string str2 = checkPalindrome(S, i , i + 1);
            if(str2.size() > longestPalindrome.size()) longestPalindrome = str2;
        }
        
        return longestPalindrome;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends