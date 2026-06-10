class Solution {
public:
    int MOD=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int length = arr.size();
        vector<int> left(length, -1);
        vector<int> right(length, length);
        stack<int> stk;

        for (int i = 0; i < length; ++i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }

        stk = stack<int>();

        for (int i = length - 1; i >= 0; --i) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }

        long long sum = 0;

        for (int i = 0; i < length; ++i) {
            sum += static_cast<long long>(i - left[i]) * (right[i] - i) * arr[i] % MOD;
            sum %= MOD;
        }

        return sum;
    }
};