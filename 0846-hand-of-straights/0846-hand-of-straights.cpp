class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        unordered_map<int,int>freq;
        for(int h:hand){
            freq[h]++;
        }
        priority_queue<int,vector<int>,greater<int>>min_pq;
        for(auto& pair:freq){
            min_pq.push(pair.first);
        }
        while(!min_pq.empty()){
            int current= min_pq.top();
            if(freq[current]==0){
                min_pq.pop();
                continue;
            }
            int group_cnt= freq[current];
            for(int i=0;i<groupSize;i++){
                int card_needed= current+i;
                if(freq[card_needed]<group_cnt){
                    return false;
                }
                freq[card_needed]-=group_cnt;
            }
            min_pq.pop();
        }
        return true;

    }
};