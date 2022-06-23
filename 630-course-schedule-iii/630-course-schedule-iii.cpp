class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
      // sorted on the basis of end time of each course as a greedy approach here at this point
        sort(courses.begin(),courses.end(),[](auto &a,auto &b){return a[1]<b[1] ; });
      
      //initialize priority queue a max heap to identify if there is a course which(which need to be        removed) is having more duration earlier 
      priority_queue<int> pq;
      int total = 0; 
      for(auto &course : courses){
        int end = course[1], dur = course[0];
        if(dur + total <= end){
          total+=dur ;
          pq.push(dur);
        }
        else if(pq.size() && pq.top()>dur ){
          total+= dur - pq.top();
          pq.pop() , pq.push(dur);
        }
      }
      
      return pq.size();
    }
};