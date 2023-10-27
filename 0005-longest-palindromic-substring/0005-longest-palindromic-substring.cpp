class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int max_len = 0;
        for (int i = 0; i < s.size(); i++){
            int j, k;
            for (j = i - 1, k = i + 1; j >= 0 and k < s.size(); j--, k++){
                if (s[j] != s[k]) break;
            }
            int len = k - j - 1;
            if (len > max_len){
                max_len = len;
                res = s.substr(j + 1, len);
            }
			
            for (j = i - 1, k = i; j >= 0 and k < s.size(); j--, k++){
                if (s[j] != s[k]) break;
            }
            len = k - j - 1;
            if (len > max_len){
                max_len = len;
                res = s.substr(j + 1, len);
            }
        }
        return res;
    }
};