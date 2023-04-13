class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int c=0;
        for(int i=0;i<pushed.size();i++)
        {
            st.push(pushed[i]);
            while(!st.empty() and st.top()==popped[c])
            {
                st.pop();
                c++;
            }
            
        }return st.empty();
    }
};