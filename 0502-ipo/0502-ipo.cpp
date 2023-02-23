class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        for(int i=0;i<profits.size();i++)
        {
            v.push_back(make_pair(capital[i],profits[i]));
        }
        sort(v.begin(),v.end());
        int n=profits.size();
        priority_queue<int>q;
        int i=0;
        while(k--)
        {
            while(i<n and v[i].first<=w)
            {
                q.push(v[i].second);
                i++;
            }
            if(q.empty())break;
            w+=q.top();
            q.pop();
        }return w;
    }
};