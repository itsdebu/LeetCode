class Solution {
public:
    void solve(string digits,vector<string>&ans,string output,int index,string mapping[])
    {
        if(index==digits.size())
        {
            ans.push_back(output);
            return;
        }
        int number=digits[index]-'0';
        string s=mapping[number];
        for(int i=0;i<s.size();i++)
        {
            output.push_back(s[i]);
            solve(digits,ans,output,index+1,mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string output;
        solve(digits,ans,output,0,mapping);
        return ans;
    }
};