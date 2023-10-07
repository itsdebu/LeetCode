class Solution {
public:
    vector<int> nsl(vector<int>&nums)
    {
        stack<int>st;
        // st.push(0);

        vector<int>next_smaller_left(nums.size());
        // next_smaller_left[0] = -1;
        for(int i=0;i<nums.size();i++)
        {
            while(!st.empty() and nums[st.top()]>=nums[i])st.pop();
            
            if(!st.empty())next_smaller_left[i] = st.top();
            else next_smaller_left[i] = -1;

            st.push(i);
        }
        return next_smaller_left;
    }

    vector<int> nsr(vector<int>&nums)
    {
        stack<int>st;
        // st.push({nums[0],0});

        vector<int>next_smaller_right(nums.size());

        // next_smaller_right[nums.size()-1] = -1;

        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty() and nums[st.top()] >= nums[i])st.pop();

            if(!st.empty())next_smaller_right[i] = st.top();
            else next_smaller_right[i] = -1;
            
            st.push(i);
        }
        return next_smaller_right;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // vector<int>width(n);

        vector<int>next_smaller_right(n);
        next_smaller_right = nsr(heights);
        vector<int>next_smaller_left(n);
        next_smaller_left = nsl(heights);

        int res = 0;
        for(int i=0;i<n;i++)
        {
           int left = next_smaller_left[i];
            int right = next_smaller_right[i];
            int  w;
            
            if(left==-1) left = -1;
            if(right==-1) right = n;
            
            w = (right-1)-(left+1)+1;
            res = max(res,heights[i]*w);
        }
        return res;
    }
};