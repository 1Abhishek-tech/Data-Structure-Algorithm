class TimeMap {
public:
  unordered_map<string , vector<pair<int,string>> > mp;
    TimeMap() {
       mp.clear(); 
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
      // vector<pair<int,string>> v = mp[key]; // We just need to be careful at single step
      // if we try to store m[key] in a variable its giving TLE as its getting copied which is again O(N).
      if(!mp.count(key))
            return "";
      // for(int i = 0 ; i < v.size() ; i++){
      //   if(v[i].first <= timestamp) ans = v[i].second;
      // }
      int low = 0 , high = mp[key].size();
      while(low < high){
        int mid = low + (high-low)/2;
        if(mp[key][mid].first > timestamp){
          high = mid;
        }
        else
          low = mid + 1;
      }
      return (low > 0) ? mp[key][low-1].second : "";
      
      // auto& v = mp[key];
      // auto it = upper_bound(v.begin(), v.end(), timestamp, [](int val, auto& p){return val < p.second;});
      // return it == v.begin() ? "" : prev(it)->first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */