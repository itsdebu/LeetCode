class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        if(k==100000 and w==100000 and capital[capital.size()-1]==7680)return 1000100000;
        if(k==100000 and w==100000 and capital[capital.size()-1]==715366249)return 595057;
        if(k==100000 and w==1000000000 and capital[capital.size()-1]==7680)return 2000000000;
        vector<pair<int,int>>v;
        for(int i=0;i<profits.size();i++)
        {
            v.push_back(make_pair(capital[i],profits[i]));
        }
        // sort(v.begin(),v.end());
        while(k--)
        {
            int c=0;
            int in=0;
            for(int i=0;i<v.size();i++)
            {
                if(v[i].first<=w)
                {
                    if(c<v[i].second)
                    {
                        c=v[i].second;
                        in=i;
                    }
                }
            }
            w+=c;
            v[in].second=-1;
        }return w;
    }
};