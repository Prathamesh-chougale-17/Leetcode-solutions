class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, vector<int>> positions;

        for (int i = 0; i < n; i++) {
            positions[nums[i]].push_back(i);
        }

        int ans = -1;

        for (auto& [x, pos] : positions) {
            vector<pair<int, int>> intervals;

            for (int i : pos) {
                int l = max(0, i - k + 1);
                int r = min(i, n - k);

                intervals.push_back({l, r});
            }

            sort(intervals.begin(), intervals.end());

            int total = 0;
            int L = intervals[0].first;
            int R = intervals[0].second;

            for (int i = 1; i < intervals.size(); i++) {
                int l = intervals[i].first;
                int r = intervals[i].second;

                if (l <= R + 1) {
                    R = max(R, r);
                } else {
                    total += R - L + 1;
                    L = l;
                    R = r;
                }
            }

            total += R - L + 1;

            if (total == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};