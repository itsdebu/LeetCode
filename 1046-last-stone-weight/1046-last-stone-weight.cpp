class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        priority_queue<int>q;
        for(int i=0;i<nums.size();i++)
        {
            q.push(nums[i]);
        }
        while(q.size()>1)
        {
            int first=q.top();
            q.pop();
            int second=q.top();
            q.pop();
            if(first>second)q.push(first-second);
        }
        if(q.empty())return 0;
        return q.top();
    }
};