class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)return tasks.size();
        unordered_map<int,int>count;
        for(char task:tasks){
            count[task]++;
        }
        priority_queue<int>pq;
        for(auto &pair:count){
            pq.push(pair.second);
        }
        //{remaining_freq, time_when next avl}
        queue<pair<int,int>>q;
        int time=0;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
                int rem_fre= pq.top()-1;
                pq.pop();
                if(rem_fre>0){
                    q.push({rem_fre,time+n});
                }
            }
            if(!q.empty() && q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};