class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        int n= asteroids.size();
        s.push(asteroids[0]);
        for(int i=1;i<n;i++){
            if(asteroids[i]<0){
                while(!s.empty() && s.top()>0 && s.top()<abs(asteroids[i])){
                    s.pop();
                }
                if(!s.empty() && s.top()>0 && s.top()>abs(asteroids[i])){
                    continue;
                }
                if(!s.empty() && s.top()>0 && s.top()<=abs(asteroids[i])){
                    s.pop();
                    continue;
                }
                s.push(asteroids[i]);
            }
            else{
                s.push(asteroids[i]);
            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};