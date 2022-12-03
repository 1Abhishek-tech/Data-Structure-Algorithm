class Solution {
public:
    class Compare{
        public : 
        bool operator()(pair<int,char> p1 , pair<int,char> p2){
            if(p1.first == p2.first) return p1.second > p2.second;
            
            return p1.first < p2.first;
        }
    };
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        
        for(auto ch : s){
            mp[ch]++;
        }
        
        priority_queue< pair<int,char> ,vector< pair<int,char> >, Compare > pq;
        
        for(auto pr : mp){
            pq.push({pr.second , pr.first});
        }
        
        string ans = "";
        while(!pq.empty()){
            int cnt = pq.top().first; char ch = pq.top().second; pq.pop();
            while(cnt){
                ans += ch; cnt--;
            }
        }
        return ans;
    }
};