class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // find row with max elemnt
            int maxRow = indexofmaxelement(mat, mid);
            int leftNeighbor = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int rightNeighbor = (mid + 1 < n) ? mat[maxRow][mid + 1] : -1;
            if (mat[maxRow][mid] > leftNeighbor &&
                mat[maxRow][mid] > rightNeighbor) {
                return {maxRow, mid};
            }
            // If the left neighbor is greater, a peak must exist in the left
            // half
            else if (leftNeighbor > mat[maxRow][mid]) {
                high = mid - 1;
            }
            // If the right neighbor is greater, a peak must exist in the right
            // half
            else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
    int indexofmaxelement(vector<vector<int>>& arr, int col) {
        int index = -1;
        int maxi = INT_MIN;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i][col] > maxi) {
                maxi = arr[i][col];
                index = i;
            }
        }
        return index;
    }
};