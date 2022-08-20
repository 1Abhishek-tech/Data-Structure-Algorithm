class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
      int n = stations.size();
      priority_queue<int> pq;
      
      int curr = startFuel;
      int i = 0 ;
      int result = 0;
      while(curr < target){ //until i reach the target
        while(i < n && curr >= stations[i][0]){
                /*
					  Sice, I am already ahead of or at this station
					  (i.e. curr >= stations[i][0])  we don't use this
					  station and try to move ahead but I store this
					  station in maxheap to use in future
				*/
          pq.push(stations[i][1]);
          i++;
        }
        if(pq.empty()) return -1;
        
        int dis = pq.top(); pq.pop();
        
        curr += dis;
        result++;
      }
      return result;
    }
};