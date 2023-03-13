class Solution {
public:
    int Roman_Value(char c)
    {
        if(c=='I')return 1;
        if(c=='V')return 5;
        if(c=='X')return 10;
        if(c=='L')return 50;
        if(c=='C')return 100;
        if(c=='D')return 500;
        if(c=='M')return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int R_to_int=0;
        for(int i=0;i<s.size();i++)
        {
            if(Roman_Value(s[i])>=Roman_Value(s[i+1]))
            {
                R_to_int+=Roman_Value(s[i]);
            }
            else
            {
                R_to_int+=Roman_Value(s[i+1])-Roman_Value(s[i]);
                i++;
            }
        }return R_to_int;
    }
};