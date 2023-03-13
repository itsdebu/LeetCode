class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
       vector<pair<int,int>>v;
        
        int n=score.size();
        vector<string>s(n,"");
        if(n==1)
        {
            s[0]="Gold Medal";
            return s;
        }
        if(n==2)
        {
            if(score[0]>score[1])
            {
               s[0]="Gold Medal";
                s[1]="Silver Medal";
                return s;
            }
            else
            {
                s[1]="Gold Medal";
                s[0]="Silver Medal";
                return s;
            }
        }
        for(int i=0;i<n;i++)
        {
            v.push_back(make_pair(score[i],i));
        }
        sort(v.begin(),v.end());
        s[v[n-1].second]="Gold Medal";
        s[v[n-2].second]="Silver Medal";
        s[v[n-3].second]="Bronze Medal";
        int x=4;
        for(int i=n-4;i>=0;i--)
        {
            s[v[i].second]=to_string(x);
            x=x-0;
            x++;
        }
        return s;
    }
};