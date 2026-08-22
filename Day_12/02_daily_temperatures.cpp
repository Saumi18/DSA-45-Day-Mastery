// Day 11 — Stack
// Problem: Daily Temperatures
//
// My notes:
// Pattern: Monotonic Decreasing Stack
// Stack stores indices of days waiting for a warmer temperature
// If current temp > stack top temp → found warmer day
// Days waited = current index - previous index
// Remaining indices have no warmer day → stay 0
// Time: O(n)
// Space: O(n)


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

