class MyCalendar {
public:
    MyCalendar() {
        
    }
    unordered_map<int,int> booking;
    bool book(int start, int end) {
        
      for(auto& [s,e] : booking){
        if(!(start >= e || end <= s)) return false;
      }
      booking[start] = end;
      return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */