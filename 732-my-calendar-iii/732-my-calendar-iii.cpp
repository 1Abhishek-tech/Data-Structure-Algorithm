class MyCalendarThree {
public:
    
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
      mp[start]++; mp[end]--;
      int cur = 0 , res = 0;
      
      for(auto event : mp){
        cur += event.second;
        res = max(cur, res);
      }
      return res;
    }
  private:
  map<int,int> mp;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */