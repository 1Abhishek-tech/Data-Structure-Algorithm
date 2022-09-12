class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // Sort The Tokens in Increasing Order
        sort(tokens.begin() , tokens.end());
        
        int score = 0, ans = 0;
        int i = 0 , j = tokens.size() ;
        while( i < j)
        {
            while(i < j && tokens[i] <= power)
                score++, power-= tokens[i++];
            // cout<<i<<" "<<power<<" "<<score<<endl;
            ans = max(ans, score);
            
            if(score)
                score-- , power+= tokens[--j];
            else break;
        }
        
        return ans;
    }
};