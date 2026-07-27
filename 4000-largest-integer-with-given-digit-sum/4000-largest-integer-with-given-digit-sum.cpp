class Solution {
public:
    int largestInteger(int n, int s) {
        int maxi=-1;
        for(int i=0;i<=1e5;i++){
            if(sum(i)==s){
                if(digit_cnt(i)<=n){
                    maxi= max(maxi,i);
                }
            }
        }
        return maxi;
    }
    int sum(int num){
        int su=0;
        while(num!=0){
            su+=num%10;
            num/=10;
        }
        return su;
    }
    int digit_cnt(int num){
        int su=0;
        while(num!=0){
            su++;
            num/=10;
        }
        return su;
    }
};