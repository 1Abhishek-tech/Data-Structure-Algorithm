class StockSpanner {
public:
    vector<int> v;
    StockSpanner() {
        
    }
    
    stack<pair<int,int> > st; //pair's fisrt is price and second is day
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().second <= price) {
            span= span+ st.top().first;
            st.pop();
        }
        st.push({span,price});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */