class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            s.insert(num);
        }
        int longest=0;
        for(int num:s){
            if(s.find(num-1)==s.end()){
                int current=1;
                int curr_num=num;
                while(s.find(curr_num+1)!=s.end()){
                    current++;
                    curr_num+=1;
                }
                longest= max(longest,current);
            }
        }
        return longest;
    }
};