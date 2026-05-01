class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>idx;
        int n= nums2.size();
        for(int i=0;i<n;i++){
            idx[nums2[i]]=i;
        }
        int m= nums1.size();
        
        for(int i=0;i<m;i++){
            bool flag=false;
            int index= idx[nums1[i]];
            int no= nums1[i];
            for(int j=index;j<n;j++){
                if(nums2[j]>no){
                    ans.push_back(nums2[j]);
                    flag=true;
                    break;
                }
            }
            if(!flag)ans.push_back(-1);
        }
        return ans;
    }
};