class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n= weights.size();
        int sum=0;
        int low=0;
        for(int s:weights){
            sum+=s;
            low= max(low,s);
        }
        
        int high=sum;
        int ans=-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(check(weights,days,mid)){
                ans= mid;
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return ans;
    }
    bool check(vector<int>&a,int d,int w){
        int s=0;
        int days=1;
        for(int x:a){
            s+=x;
            if(s>w){
                days++;
                s=x;
            }
        }
        if(days<=d)return true;
        else return false;
    }
};