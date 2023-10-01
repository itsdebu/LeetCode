class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string temp;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')temp+=s[i];
            else
            {
                reverse(temp.begin(),temp.end());
                // cout<<"temp"<<endl;
                ans+=temp;
                ans+=' ';
                temp = "";
                // cout<<ans;
            }
        }
        if(temp.size()!=0)reverse(temp.begin(),temp.end());

        ans+=temp;
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};