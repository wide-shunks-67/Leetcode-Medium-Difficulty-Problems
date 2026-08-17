class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        int mini = INT_MAX;
        int index = -1;
        for (int i = 0; i < n; i++) {
            int dis =
                abs(target[0] - drones[i][0]) + abs(target[1] - drones[i][1]);
            if (dis <= drones[i][2]) {
                if (dis < mini) {
                    mini = dis;
                    index = i;
                }
            }
        }
        return index;
    }
};