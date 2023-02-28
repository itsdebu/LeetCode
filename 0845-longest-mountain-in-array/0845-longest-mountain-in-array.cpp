class Solution {
public:

    int longestMountain(vector<int>& arr) {
        // support variables
        int res = 0, curr = 0, len = arr.size();
        bool isMountain = false, isDescending = false;
        for (int i = 1; i < len; i++) {
            // checking if we are climbing
            if (arr[i] > arr[i - 1]) {
                // reset conditions: either we were descending or we were
                // not yet in a mountain
                if (isDescending || !isMountain) {
                    isDescending = false;
                    isMountain = true;
                    curr = 1;
                }
                curr++;
            }
            // checking if we are already in a mountain
            else if (isMountain) {
                // if we start descending
                if  (arr[i] < arr[i - 1]) {
                    isDescending = true;
                    res = max(++curr, res);
                }
                // if we reach a plateau
                else if (arr[i] == arr[i - 1]) isMountain = false;
            }
        }
        return res;
    }
};