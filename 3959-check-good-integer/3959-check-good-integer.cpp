class Solution {
public:
    bool checkGoodInteger(int n) {
        long long digit_sum= check_sum(n);
        long long square_sum= check_square_sum(n);\
        if(square_sum-digit_sum >=50)return true;
        else return false;
    }
    long long check_sum(int n){
        long long sum=0;
        while(n!=0){
            long long x= n%10;
            sum+=x;
            n=n/10;
        }
        return sum;
    }
    long long check_square_sum(int n){
        long long sum=0;
        while(n!=0){
            long long x= n%10;
            sum+=(x * x);
            n=n/10;
        }
        return sum;
    }
};