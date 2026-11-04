class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // Step 1: Calculate cost of every window of size x
        vector<long long> cost(n - x + 1);

        multiset<int> left, right;

        long long sumLeft = 0, sumRight = 0;

        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                auto it = prev(left.end());
                int val = *it;

                left.erase(it);
                sumLeft -= val;

                right.insert(val);
                sumRight += val;
            }

            while (left.size() < right.size()) {
                auto it = right.begin();
                int val = *it;

                right.erase(it);
                sumRight -= val;

                left.insert(val);
                sumLeft += val;
            }
        };

        auto add = [&](int val) {
            if (left.empty() || val <= *prev(left.end())) {
                left.insert(val);
                sumLeft += val;
            } else {
                right.insert(val);
                sumRight += val;
            }

            balance();
        };

        auto remove = [&](int val) {
            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                sumLeft -= val;
            } else {
                it = right.find(val);
                right.erase(it);
                sumRight -= val;
            }

            balance();
        };

        auto getCost = [&]() -> long long {
            long long median = *prev(left.end());

            long long leftCost =
                median * (long long)left.size() - sumLeft;

            long long rightCost =
                sumRight - median * (long long)right.size();

            return leftCost + rightCost;
        };

        // First window
        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        // Sliding window
        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost[i - x + 1] = getCost();
        }

        // Step 2: DP
        const long long INF = 1e18;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                // Skip current element
                curr[i] = curr[i - 1];

                // Take a window of size x
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
