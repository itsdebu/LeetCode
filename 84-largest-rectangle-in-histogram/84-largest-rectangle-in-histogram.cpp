class Solution {
public:
    vector<int> ngl(vector<int>arr)
    {
        stack<int>st;
        vector<int>left(arr.size());
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty() and arr[st.top()]>=arr[i])st.pop();
            if(st.empty())left[i]=-1;
            else left[i]=st.top();
            st.push(i);
        }
        return left;
    }
    vector<int> ngr(vector<int>arr)
    {
        stack<int>st;
        vector<int>right(arr.size());
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!st.empty() and arr[st.top()]>=arr[i])st.pop();
            if(st.empty())right[i]=-1;
            else right[i]=st.top();
            st.push(i);
        }
        return right;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left(heights.size()),right(heights.size());
        left=ngl(heights);
        right=ngr(heights);
        int res = INT_MIN;
        
        for(int i=0; i<heights.size(); i++){
            int l = left[i];
            int r = right[i];
            int  w;
            
            if(l==-1) l= -1;
            if(r==-1) r = heights.size();
            
            w = (r-1)-(l+1)+1;
            res = max(res,heights[i]*w);
        }
        return res;
    }
};