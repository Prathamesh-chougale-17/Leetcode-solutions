class Solution {
public:
    unordered_map<long long, bool> dp;

    bool cal(int pos, int jump, vector<int>& stones,
             unordered_set<int>& st) {

        if (st.find(pos) == st.end())
            return false;

        if (pos == stones.back())
            return true;

        long long key = ((long long)pos << 32) | jump;

        if (dp.find(key) != dp.end())
            return dp[key];

        for (int nextJump = jump - 1;
             nextJump <= jump + 1;
             nextJump++) {

            if (nextJump <= 0)
                continue;

            if (cal(pos + nextJump, nextJump, stones, st))
                return dp[key] = true;
        }

        return dp[key] = false;
    }

    bool canCross(vector<int>& stones) {

        if (stones[1] != 1)
            return false;

        unordered_set<int> st(stones.begin(), stones.end());

        return cal(0, 0, stones, st);
    }
};