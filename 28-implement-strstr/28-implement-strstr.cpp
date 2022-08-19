class Solution {
public:
    int strStr(string h, string n) {
        int i=0,j=0;
        if(h.size()<n.size())return -1;
        while(i<=h.size() and j<=n.size())
        {
            if(h[i]==n[j])
            {
                i++,j++;
                if(j==n.size())return i-j;
            }
            else
            {
                i=i-j+1;
                j=0;
            }
        }return -1;
        
    }
};