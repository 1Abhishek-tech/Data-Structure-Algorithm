class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        if(n == 1) return s;
        
        stack<char> st;
        st.push(s[0]);
        
        for(int i = 1 ; i < n ; i++){
            if(!st.empty() && abs(st.top() - s[i]) == 32){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top(); st.pop();
        }
        
        reverse(ans.begin() , ans.end());
        return ans;
        // string ans;
        //  int flag=1;
        // while(flag){
        //     string str;
        //     int prev=s.size();
        //     int i=0;
        // for(i=0;i<s.size()-1;i++){
        //     if(s[i]-'a'==s[i+1]-'A'||s[i]-'A'==s[i+1]-'a')i++; //if (abs(currChar - nextChar) == 32) 
        //     else str.push_back(s[i]);
        // }
        // if(i<s.size()){
        // str.push_back(s[i]);
        // }
        // if(str.size()==prev||str.size()==0){
        //     ans=str;
        //     flag=0;
        // }
        // else{
        //     s=str;
        // }
        // }
        // return ans;
    }
};