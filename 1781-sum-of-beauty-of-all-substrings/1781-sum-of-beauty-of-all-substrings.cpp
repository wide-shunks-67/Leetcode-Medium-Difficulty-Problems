class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;
            freq[s[i]]++;
            int max_fre = INT_MIN;
           
            for (int j = i + 1; j < n; j++) {
                freq[s[j]]++;
                int min_fre = INT_MAX;
                max_fre = max(max_fre, freq[s[j]]);
                for (auto it : freq) {
                    min_fre = min(min_fre, it.second);
                }
                sum += max_fre - min_fre;
            }
        }
        return sum;
    }
};