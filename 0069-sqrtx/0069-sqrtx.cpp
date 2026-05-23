class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        int left=1;
        int right=x;
        while(left<=right){
            long long mid= (left) + (right-left)/2;
            if(mid*mid==(long long)x)return (int)mid;
            if(mid*mid>(long long )x)right= mid-1;
            else left= mid+1;
        }
        return round(right);
    }
};