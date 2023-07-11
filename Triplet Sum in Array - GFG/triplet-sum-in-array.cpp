//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A , A + n);
        for(int i = 0 ; i < n - 2 ; i++){
            // A[i] + A[low] + A[high];
            int low = i + 1 , high = n - 1;
            // int small_target = X - A[i] - A[low] - A[high];
            
            while(low < high){
                // int sum = A[i] + A[low] + A[high];
                int small_target = X - A[i] - A[low] - A[high];
                if(small_target == 0){
                    return true;
                }
                else if(small_target > 0 ){
                    low++;
                }
                else high--;
            }
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends