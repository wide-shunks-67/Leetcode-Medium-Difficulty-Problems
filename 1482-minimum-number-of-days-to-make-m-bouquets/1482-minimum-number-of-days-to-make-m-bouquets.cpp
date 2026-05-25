class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n= bloomDay.size();
        if((long long)m*k>n)return -1;
        int mini= INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mini= min(mini,bloomDay[i]);
            maxi= max(maxi,bloomDay[i]);
        }
        while(mini<=maxi){
            int mid= mini+ (maxi-mini)/2;
            if(possible(bloomDay,mid,m,k)){
                maxi= mid-1;
            }
            else{
                mini=mid+1;
            }
        }
        return mini;
    }
    bool possible(vector<int>days, int d,int m,int k){
        int n= days.size();
        int cnt=0;
        int no_of_bou=0;
        for(int i=0;i<n;i++){
            if(days[i]<=d){
                cnt++;
            }
            if(days[i]>d){
                no_of_bou+=cnt/k;
                cnt=0;
            }
        }
        no_of_bou+=cnt/k;
        if(no_of_bou>=m)return true;
        else return false;
    }
};