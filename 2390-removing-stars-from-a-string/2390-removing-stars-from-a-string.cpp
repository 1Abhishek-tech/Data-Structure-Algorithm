class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        if(n == 1) return s;
        
        vector<char> v;
        v.push_back(s[0]);
        
        for(int i = 1 ; i < n ; i++){
            if(s[i] != '*') v.push_back(s[i]);
            
            else if(v.size()) v.pop_back();
        }
        
        s = "";
        for(int i = 0 ; i < v.size() ; i++) s += v[i];
        
        return s;
    }
};