class Solution {
public:
    int merge(vector<int>& nums, int p, int q, int r, int cnt) {
        int n1 = q - p + 1;
        int n2 = r - q;
        vector<int> L1(n1);
        vector<int> L2(n2);
        for (int i = 0; i < n1; i++) {
            L1[i] = nums[p + i];
        }
        for (int i = 0; i < n2; i++) {
            L2[i] = nums[q + i + 1];
        }
        int in=0;
        for (int j = 0; j < n2; j++) {
            while (in < n1 && (long long)L1[in] <= (long long)2 * L2[j]) {
                in++;
            }
            cnt += (n1 - in); 
        }

        int i = 0;
        int j = 0;
        int k = p;
        while (i < n1 && j < n2) {
            if (L1[i] <= L2[j]) {

                nums[k] = L1[i];
                k++;
                i++;
            } else {

                nums[k] = L2[j];
                k++;
                j++;
            }
        }
        while (i < n1) {
            nums[k] = L1[i];
            i++;
            k++;
        }
        while (j < n2) {
            nums[k] = L2[j];
            j++;
            k++;
        }
        return cnt;
    }

    int merge_sort(vector<int>& nums, int p, int r, int cnt) {
        if (p >= r)
            return 0;
        int q = (p + r) / 2;
        int left_cnt = merge_sort(nums, p, q, cnt);
        int right_cnt = merge_sort(nums, q + 1, r, cnt);
        int cross_count = merge(nums, p, q, r, cnt);

        return left_cnt + right_cnt + cross_count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        cnt = merge_sort(nums, 0, n - 1, cnt);
        return cnt;
    }
};