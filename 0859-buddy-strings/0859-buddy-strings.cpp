class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())return 0;
        unordered_map<int,int>mp;
        if(s==goal)
        {
            for(auto i:s)mp[i]++;
            for(auto i:mp)
            {
                if(i.second>1)return true;
            }
            return false;
        }
        int fi=-1;
        int si=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=goal[i] and fi==-1)
            {
                fi=i;
            }
            if(s[i]!=goal[i] and fi!=-1)si=i;
        }
        swap(s[fi],s[si]);
        return s==goal;
    }
};