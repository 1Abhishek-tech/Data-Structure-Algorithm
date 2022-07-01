// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    int minStepsTopDown(int N,int dp[]){
        //Base Case
        if(N == 1)
            return 0;
        //if memorised    
        if(dp[N] != 0)
            return dp[N];
        //if not memorised subproblem
        int op1,op2,op3 ;
        op1 = op2 = op3 = INT_MAX;
        if(N%3 == 0)
            op3 = minStepsTopDown(N/3,dp) + 1;
        if(N%2 == 0)
            op2 = minStepsTopDown(N/2,dp) + 1;
        op1 = minStepsTopDown(N-1,dp) + 1;
        
        int ans = min(min(op3,op2),op1);
        return dp[N] = ans;
    }
	public:
	int minSteps(int N) 
	{ 
	    // Your code goes here
	    int dp[10000] = {0};
	    return minStepsTopDown(N,dp);
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.minSteps(n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends