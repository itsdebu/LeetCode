class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // if(s.size()==0 )
        string temp_s = "" , temp_t = "";

        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='#')
            {
                temp_s += s[i];
            }
            else{
                if(temp_s.size()>0)temp_s.pop_back();
            }
        }
        for(int i=0;i<t.size();i++)
        {
            if(t[i]!='#')
            {
                temp_t += t[i];
            }
            else
            {
                if(temp_t.size()>0)temp_t.pop_back();
            } 
        }
        return temp_t == temp_s;
    }
};