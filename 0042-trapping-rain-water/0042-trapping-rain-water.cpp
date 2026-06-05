class Solution {
public:
    int trap(vector<int>& height) {
      int n= height.size();
      vector<int>left_max_prefix(n);
      left_max_prefix[0]=0;
      for(int i=1;i<n;i++){
        left_max_prefix[i]= max(left_max_prefix[i-1],height[i-1]);
      } 
       vector<int>right_max_suffix(n);
      right_max_suffix[n-1]=0;
      for(int i=n-2;i>=0;i--){
        right_max_suffix[i]= max(right_max_suffix[i+1],height[i+1]);
      } 
      int cost=0;
      for(int i=0;i<n;i++){
        if(height[i]<left_max_prefix[i] && height[i]<right_max_suffix[i]){
            cost+=(min(left_max_prefix[i],right_max_suffix[i]) - height[i]);
        }
      }
      return cost;
    }
};