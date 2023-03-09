class Solution {
public:
    int maxVowels(string s, int k) {
        int count=0,mx=0;
        int i=0,j=0;
        if(s.size()>k)
        {
            for(int i=0;i<k;i++)
            {
                if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u')count++;
            }
            mx=count;
            i=1,j=1;
            while(j<s.size())
            {
                if(j-i+1==k)
                {
                    if(s[i-1]=='a' or s[i-1]=='e' or s[i-1]=='i' or s[i-1]=='o' or s[i-1]=='u')count--;
                    if(s[j]=='a' or s[j]=='e' or s[j]=='i' or s[j]=='o' or s[j]=='u')count++;
                    cout<<count<<endl;
                    mx=max(mx,count);
                    i++,j++;
                }
                else {
                    j++;
                }
            }
        }
        else
        {
            for(int i=0;i<k;i++)
            {
                if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u')count++;
            }
            mx=count;
        }
        return mx;
    }
};