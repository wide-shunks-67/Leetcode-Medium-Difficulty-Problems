class Solution {
public:
    
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        vector<pair<int, char>> a;
        for (auto& it : freq) {
            a.push_back({it.second, it.first});
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        string ans = "";
        for(auto pair: a){
            while(pair.first!=0){
                ans+=pair.second;
                pair.first--;
            }
        }
        return ans;
    }
};