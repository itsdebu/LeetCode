class Solution {
public:
    bool isVowel(char a)
    {
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')return true;
        else return false;
    }
    int maxVowels(string s, int k) {
        int mx=INT_MIN;
        int i=1,j=1;
        int count=0;
        for(int i=0;i<k;i++)
        {
            if(isVowel(s[i]))count++;
        }
        mx=count;
        while(j<s.size())
        {
            if(j-i+1==k)
            {
                if(isVowel(s[i-1]))count--;
                if(isVowel(s[j]))count++;
                mx=max(count,mx);
                i++,j++;
            }
            else j++;
        }return mx;
    }
};