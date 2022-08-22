class Solution {
public:
    int firstUniqChar(string s) {
        for(int i=0;i<s.length();i++)
        {
            bool flag = false;
            for(int j=0;j<s.length();j++)
            {
                if(i!=j && s[i] == s[j])
                {
                    flag = true;
                    break;
                }
            }
            
            if(flag == false)
                return i;
        }
        return -1;
    }
};