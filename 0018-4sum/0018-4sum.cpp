class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long long target) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        // 1. Sort the array: Essential for the two-pointer technique and duplicate handling.
        sort(nums.begin(), nums.end());
        
        // Use 'long long' for the target and sum to prevent overflow, 
        // as intermediate sums can exceed 32-bit integer limits.
        
        // Outer loop: Fix the first element (nums[i])
        for (int i = 0; i < n; ++i) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // Second loop: Fix the second element (nums[j])
            for (int j = i + 1; j < n; ++j) {
                // Skip duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                
                // 2. Two-Pointer setup: Search for the remaining two elements
                int left = j + 1;
                int right = n - 1;
                
                // Calculate the required sum for the remaining two elements
                long long remainingTarget = target - (long long)nums[i] - nums[j];

                // Inner while loop: Two-Pointer search
                while (left < right) {
                    long long currentSum = (long long)nums[left] + nums[right];

                    if (currentSum == remainingTarget) {
                        // Found a valid quadruplet
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // 3. Move pointers and skip duplicates for the third and fourth elements
                        
                        // Skip duplicates for the third element (left)
                        int thirdElement = nums[left];
                        while (left < right && nums[left] == thirdElement) {
                            left++;
                        }

                        // Skip duplicates for the fourth element (right)
                        int fourthElement = nums[right];
                        while (left < right && nums[right] == fourthElement) {
                            right--;
                        }

                    } else if (currentSum < remainingTarget) {
                        // Need a larger sum, move left pointer
                        left++;
                    } else { // currentSum > remainingTarget
                        // Need a smaller sum, move right pointer
                        right--;
                    }
                }
            }
        }
        
        return ans;
    }
};