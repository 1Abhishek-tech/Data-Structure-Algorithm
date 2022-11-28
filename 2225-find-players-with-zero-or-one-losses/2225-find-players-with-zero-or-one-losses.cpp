class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        
        unordered_map< int,pair<int,int> > mp; 
        // mp[i].first --> player i wins count
        // mp[i].second --> player i losses count
        
        for(int i = 0 ; i < n ; i++){
            // matches[i][0] 
            // matches[i][1];
                
            mp[matches[i][0]].first++; // winning count of player i
            mp[matches[i][1]].second++; // losses count of player i
        }
        
        vector<int> neverL;
        vector<int> lostOnce;
        
        for(auto pr : mp){
            if(pr.second.second == 0) neverL.push_back(pr.first);
            
            if(pr.second.second == 1) lostOnce.push_back(pr.first);
            
        }
        sort(neverL.begin() , neverL.end());
        sort(lostOnce.begin() , lostOnce.end());

        return {neverL , lostOnce};
        
    }
};