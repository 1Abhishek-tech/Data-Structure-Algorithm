class Solution
{
    public:
        int maximumUniqueSubarray(vector<int> &nums)
        {
            int n = nums.size();

            vector<int> prefixSum(n + 1, 0);

            unordered_map<int, int> mp;

            for (int i = 1; i <= n; i++)
            {
                prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
            }

            int answer = 0;

            int i = 0;
            int j = 0;

            while (j < n)
            {

                if (mp.find(nums[j]) != mp.end())
                {
                    int previousEncounter = mp[nums[j]];

                    while (i <= previousEncounter)
                        i++;
                }
                mp[nums[j]] = j;

                answer = max(answer, prefixSum[j + 1] - prefixSum[i]);

                j++;
            }

            return answer;
        }
};