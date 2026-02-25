class Solution {

public:
    static bool compare(const pair<int,int>&a, const pair<int,int>&b){
        if(a.second==b.second)return a.first<b.first;
        return a.second<b.second;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>ans;
        int n= arr.size();
        for(int i=0;i<n;i++){
            uint32_t num= arr[i];
            int count= __builtin_popcount(num);
            ans.push_back({arr[i],count});
        }
        sort(ans.begin(),ans.end(),compare);
        vector<int>a;
        for(auto it:ans){
            a.push_back(it.first);
        }
        return a;
    }
};