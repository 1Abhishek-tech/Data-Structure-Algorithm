// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    
    // bool comp(pair<int,int> p1,pair<int,int> p2){
        
    //     return p1.second < p2.second;
    // }
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int> > activity;
        int f,s;
        for(int i=0;i<n;i++){
            // f = start[i];
            // s = end[i];
            activity.push_back({end[i],start[i]});
        }
        sort(activity.begin(),activity.end());
        
        int res = 1;
        int ending_time = activity[0].first;
        
        for(int i=1;i<n;i++){
            if(activity[i].second>ending_time){
                ending_time = activity[i].first;
                res++;
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends