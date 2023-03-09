class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0, len = s.length(), Max = 0;
        for(int i=0;i<k;i++)    
            if(isVowel(s[i])) 
               count++;
        Max = max(Max, count);
        for(int i=k;i<len;i++){
            if(isVowel(s[i])) count++;
            if(isVowel(s[i-k])) count--;
            Max = max(Max, count);
        }
        return Max;
    }
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
};