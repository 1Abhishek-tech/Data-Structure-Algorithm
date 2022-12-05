class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        // find the sum of all elements in an array

        long long int totalSum = 0;

        for(int i = 0; i<nums.size(); i++)
        {
            totalSum +=nums[i];
        }

        // Declare the required variables
        long long int firstSum = 0;
        long long int secondSum = 0;
        long long int averageFirst = 0;
        long long int averageSecond = 0;

        int ans  = 0;
        long long int mini = INT_MAX;

        // Now Iterate through the loop

        int n = nums.size();

        for(int i = 0;i<n;i++)
        {
            firstSum +=nums[i];

            secondSum = totalSum - firstSum;

            averageFirst = firstSum/(i+1);
            

            //Check for the second average
            
            if(secondSum!=0)
                averageSecond = secondSum/(n-i-1);
            else
                averageSecond = 0;

            // Calculate the absolute difference

            int temp = abs(averageFirst-averageSecond); 

            // Check for the minimum difference

            if(mini > temp)
            {
                mini = temp;
                ans = i;
            }       
        }
        return ans;   
    }
};