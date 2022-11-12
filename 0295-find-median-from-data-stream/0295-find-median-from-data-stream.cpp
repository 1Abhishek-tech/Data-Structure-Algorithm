class MedianFinder {
public:
    MedianFinder() {
        
    }
    // by default pq is maxheap in cpp
//     priority_queue<int> pq; //max-heap
    
//     void addNum(int num) {
//         pq.push(num);
//     }
    priority_queue<int> decreasing;
    priority_queue<int, vector<int>, greater<int>> increasing;
    bool evn = true;
    void addNum(int num) {
        evn =!evn;
        if(!evn){
        decreasing.push(num);
        increasing.push(decreasing.top());
        decreasing.pop();}
        else{
              increasing.push(num);
              decreasing.push(increasing.top());
              increasing.pop();
        }
      
    }
    double findMedian() {
        if (!evn) return increasing.top();
        return (decreasing.top() + increasing.top()) / 2.0;
    }
    // double findMedian() {
    //     int n = pq.size();
    //     if(n == 1) return pq.top();
    //     stack<int> st;
    //     double ans;
    //     if(n%2 == 0){
    //         int i = n/2;
    //         while(i){
    //             st.push(pq.top()); pq.pop();
    //             i--;
    //         }
    //         int elem1 = st.top(); int elem2 = pq.top();
    //         ans = (float)(elem1+elem2)/2;
    //         while(!st.empty()){
    //             pq.push(st.top());
    //             st.pop();
    //         }
    //     }
    //     else{
    //         int i = n/2;
    //         while(i){
    //             st.push(pq.top()); pq.pop();
    //             i--;
    //         }
    //         int elem = pq.top(); ;
    //         ans = (float)elem;
    //         while(!st.empty()){
    //             pq.push(st.top());
    //             st.pop();
    //         } 
    //     }
    //     return ans;
    // }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */