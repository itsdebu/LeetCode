class Solution {
public:

int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
	
    unordered_map<int, bool> mp;
    
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]] = true;
    }
    
    int maxCount = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        int count = 0;
        int num = nums[i];
        int tempNum = num;
        
        while (mp[tempNum] == true) {
            mp[tempNum] = false;
            tempNum++;
            count++;
        }
        
        tempNum = num-1;
        
        while (mp[tempNum] == true) {
            mp[tempNum] = false;
            tempNum--;
            count++;
        }
        
        maxCount = max(maxCount, count);
    }
    return maxCount;
}
};