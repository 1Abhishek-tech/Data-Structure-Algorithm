class Solution
{
    public:
        typedef long long ll;
    bool isPossible(vector<int> &target)
    {
        priority_queue<ll> pq(target.begin(), target.end());
        ll sum = 0, n = target.size();
        for (int &num: target)
            sum += num;

        while (!pq.empty())
        {
            ll x = pq.top();
            sum -= x;
            if (x <= sum || sum == 0) break;

            ll r = x % sum;
            x = (r == 0) ? sum : r;

            pq.pop();
            sum += x;
            pq.push(x);
        }

        return (pq.size() == n) && (pq.top() == 1);
    }
};