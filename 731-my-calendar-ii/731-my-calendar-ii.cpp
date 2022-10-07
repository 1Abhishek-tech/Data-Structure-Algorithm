class MyCalendarTwo {
  map<int,int> mp;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++; mp[end]--;
      int cur = 0 , res = 0;
      for(auto &event : mp){
        cur += event.second;
        if(cur == 3){
          mp[start]-- , mp[end]++ ;
          return false;
        }
      }
      return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */