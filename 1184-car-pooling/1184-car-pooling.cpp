// Prefix Sum Array Soln
// Time: O(N^2) where N is no. of elements in vector trips
// Space: O(N) where N is no. of elements in vector trips

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        vector<int> v(1000, 0);
        for (int i = 0; i < trips.size(); i++) {
            for (int j = trips[i][1]; j < trips[i][2]; j++) {
                v[j] += trips[i][0];
                if (v[j] > capacity) {
                    return false;
                }
            }
        }
        return true;
    }
};