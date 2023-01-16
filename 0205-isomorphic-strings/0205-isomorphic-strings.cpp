class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return 0;
        
        unordered_map<char,char>mp,mp1;
        
        for(int i=0; i<s.size(); i++){
            if(mp.count(s[i])==0){
                if(mp1.find(t[i])!=mp1.end())
                    return 0;
                mp[s[i]]=t[i];
                mp1[t[i]]=s[i];
            } else if(t[i]!=mp[s[i]])
                return 0;
        }
        return 1;
    }
};