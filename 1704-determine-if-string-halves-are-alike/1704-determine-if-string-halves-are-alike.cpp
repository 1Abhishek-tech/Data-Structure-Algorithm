class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int n = s.length();
        int a = 0 , b = 0;
        for(int i = 0 ; i < n/2 ; i++){
            if(isVowel(s[i])) a++;
        }
        for(int i = n/2 ; i < n ; i++){
            if(isVowel(s[i])) b++;
        }
        
        return a == b;
    }
};