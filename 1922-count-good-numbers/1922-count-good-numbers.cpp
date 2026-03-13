class Solution {
public:
    int M = 1e9 + 7;
    long long pow(long long base, long long exp) {
        if(exp==0)return 1;
        long long ans= 1;
        while(exp>0){
            if(exp%2==0){
                base = (base * base) %M;
                exp=exp/2;
            }
            else{
                ans=(ans*base)% M;
                exp-=1;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long even;
        long long odd;
        if (n % 2 == 1) {
            even = n / 2 + 1;
            odd = n / 2;
        } else {
            even = n / 2;
            odd = even;
        }
        long long even_ans = pow(5, even);
        long long odd_ans = pow(4, odd);
        return (even_ans * odd_ans) % M;
    }
};