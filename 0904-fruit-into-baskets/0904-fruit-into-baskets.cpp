class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n= fruits.size();
        int l=0;
        unordered_map<int,int>bas;
        int len=0;
        for(int r=0;r<n;r++){
            bas[fruits[r]]++;
            while(bas.size()>2){
                bas[fruits[l]]--;
                if(bas[fruits[l]]==0){
                    bas.erase(fruits[l]);
                }
                l++;
            }
            len= max(len,r-l+1);
        }
        return len;
    }
};