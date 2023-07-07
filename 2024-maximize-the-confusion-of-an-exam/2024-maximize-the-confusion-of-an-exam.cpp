class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int i=0,j=0;
        int fcount=0,tcount=0;
        int ans=INT_MIN;
        while(j<s.size())
        {
            if(s[j]=='F')fcount++;
            else tcount++;
            while(min(fcount,tcount)>k)
            {
                if(s[i]=='F')fcount--;
                else tcount--;
                i++;
            }
            ans=max(ans,tcount+fcount);
            j++;
        }return ans;
    }
};