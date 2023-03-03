class Solution {
public:
    vector<char>char_array(int n)
    {
        vector<char>v;
        while(n!=0)
        {
            v.push_back((n%10)+ '0');
            n/=10;
        }
        reverse(v.begin(),v.end());
        return v;
    }
    int compress(vector<char>& chars) {
        if(chars.size()==1)return 1;
        char curr_char=chars[0];
        int freq_count=0;
        int write_index=0;
        for(int i=0;i<=chars.size();i++)
        {
            if(i!=chars.size() and chars[i]==curr_char)freq_count++;
            else
            {
                chars[write_index++]=curr_char;
                if(freq_count!=1)
                {
                    vector<char>frq_arr=char_array(freq_count);
                    for(auto number:frq_arr)
                    {
                        chars[write_index++]=number;
                    }
                }
                if(i!=chars.size())curr_char=chars[i];
                freq_count=1;
            }
        }return write_index;
    }
};