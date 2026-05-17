class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int cnt=0;
        if(k==1)return r-l+1;
        for(int i=0;;i++){
            long long val=pow(i,k);
            if(val>r){
                break;
            }
            if(val>=l)cnt++;
        }
        return cnt;
    }
};