class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.length();
        
        stack<string> st;
        
        string word = "";
        for(int i = 0 ; i < n ; i++){
            if(s[i] != ' ')
              word += s[i];
            else{
                if(word != " " && word != "")
                  st.push(word);
                word = "";
            }
            
        }
        if(word != "") st.push(word);
        
        string ans = "";
        while(!st.empty()){
            ans += st.top(); st.pop();
            if(!st.empty())
              ans += " ";
        }

        return ans;
        
    }
};